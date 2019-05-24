#include "path.h"
#include "command.h"
#include "directory.h"
#include "error.h"
#include "common.h"
#include "array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <dirent.h>
#include <getopt.h>
#include <string.h>

typedef struct str_path {
    // path name
    char name[128];

    // path
    char path[256];
} path;

int path_list_cmd(int argc, char **argv);
int path_find_cmd(int argc, char **argv);
int path_add_cmd(int argc, char **argv);
int path_edit_cmd(int argc, char **argv);
int path_rm_cmd(int argc, char **argv);

void path_usage(void);
array* path_get_all(void);
int path_init(void);
int path_save(path p);
path* path_find(char name[]);
char* path_get_path(char path[]);
int path_rm_path(path p);

char *pathDirPath;
#define PATH_DIR "paths"

#define UNEXISTING_PATH_E "Unexisting path"
#define EXISTING_PATH_E  "Path already exists"

// Subcommands
static cmd subcommands[] = {
        {"list", path_list_cmd },
        {"find", path_find_cmd},
        {"add", path_add_cmd },
        {"edit", path_edit_cmd},
        {"rm", path_rm_cmd },
        {0}
};

int path_cmd(int argc, char **argv) {
    if(argc) {
        cmd *subcommand = getCommand(argv[0], subcommands);
        if(subcommand) {
            subcommand->run(--argc, ++argv);

            return errno;
        }
        error(UNKNOWN_CMD_E);
    }

    path_usage();

    return 0;
}

int path_init(void) {
    asprintf(&pathDirPath, "%s/%s", PIT_PATH, PATH_DIR);

    // Create path dir if it does not exists
    if (dir_exists(pathDirPath) != true) {
        if(_create_dir(pathDirPath) != 0) {
            e_error(UNEXP_E);
        }
    }

    return true;
}

// Subcommands

int path_list_cmd(int argc, char **argv) {
    char *pathName, *pathFilePath, *pathPath = NULL;
    FILE *pathFile = NULL;
    int fName = 0;

    // Parse options
    for (int i = 0; i < argc; i++ ) {
        if (! (strcmp(argv[i], "-n") && strcmp(argv[i], "--name"))) {
            fName = 1;
        }
    }

    DIR *dir;
    struct dirent *d;
    if (dir = opendir(pathDirPath)) {
        while ((d = readdir(dir)) != NULL) {
            pathName = d->d_name;
            if (strcmp(pathName, ".") && strcmp(pathName, "..")){
                pathFilePath = path_get_path(pathName);
                if ((pathFile = fopen(pathFilePath, "r")) != NULL) {
                    pathPath = calloc(128, sizeof(char));
                    fgets(pathPath, 128, pathFile);

                    if (fName) {
                        printf("%s\t", pathName);
                    } else {
                        printf("%s\t%s\n", pathName, pathPath);
                    }

                    fclose(pathFile);
                }
            }

        }
        closedir(dir);
    }

    if (fName) {
        printf("\n");
    }

    return 0;
};

int path_find_cmd(int argc, char **argv) {

    if (argc == 1) {
        // Find file
        path *p = path_find(argv[0]);
        if (p != NULL) {
            printf("%s\n", p->path);
        }
    } else {
        error(INVALID_NUM_ARGS_E);
        path_usage();

        return 1;
    }

    return 0;
}

int path_add_cmd(int argc, char **argv) {
    path p;

    if(argc == 2) {
        // Check path does not exists
        if (path_find(argv[0]) == NULL) {
            strcpy(p.name, argv[0]);
            strcpy(p.path, realpath(argv[1], NULL));

            path_save(p);
        } else {
            e_error(EXISTING_PATH_E);
        }
    } else {
        error(INVALID_NUM_ARGS_E);
        path_usage();

        exit(1);
    }
}

int path_edit_cmd(int argc, char **argv) {
    path *p;

    if (argc == 2) {
        // Check path does not exists
        if ((p = path_find(argv[0])) != NULL) {
            strcpy(p->path, argv[1]);

            path_save(*p);
        } else {
            e_error(UNEXISTING_PATH_E);
        }

        return 0;
    } else {
        error(INVALID_NUM_ARGS_E);
        path_usage();

        exit(1);
    }
}

int path_rm_cmd(int argc, char **argv) {
    path *p;

    if (argc == 1) {
        if ((p = path_find(argv[0])) != NULL) {
            remove(path_get_path(p->name));
            return 0;
        } else {
            e_error(UNEXISTING_PATH_E);
        }
    } else {
        error("Number of arguments non valid\n");
        path_usage();
        exit(1);
    }
}


// Help functions

int path_save(path p) {
    FILE *pathFile;

    char *pathFilePath = path_get_path(p.name);
    if ((pathFile= fopen(pathFilePath, "w")) != NULL) {
        fputs(p.path, pathFile);
        fclose(pathFile);

        return 0;
    }

    return 1;
}

void path_usage(void) {
    fprintf(stderr,
        "usage: pit path <options>\n"
        "\n"
        "The path command let define some paths for pit\n"
        "\n"
        "<options>\n"
        "\tlist                     List all paths defined\n"
        "\tfind <path_name>         Return the path for <path_name>\n"
        "\tadd <path_name> <path>   Add a new <path> to pit with name <path_name>\n"
        "\tedit <path_name> <path>  Changes the <path> named <path_name>\n"
        "\trm <path_name>           Remove the path defined as <path_name>\n"
    );
}

path* path_find(char name[]) {
    char *pathFilePath = path_get_path(name);
    FILE *pathFile;
    path *p = malloc(sizeof(path));

    if (pathFilePath != NULL) {
        if (file_exists(pathFilePath)) {

            if ((pathFile = fopen(pathFilePath, "r"))) {
                strcpy(p->name, name);
                fgets(p->path, 128, pathFile);


                return p;
            }
        }
    }

    return NULL;
}

char* path_get_path(char *pathName) {
    char *pathPath = NULL;

    if (is_valid_filename(pathName) == true) {
        pathPath = malloc(128 *  sizeof(char));

        snprintf(pathPath, 128, "%s/%s", pathDirPath, pathName);

        return pathPath;
    }

    return NULL;
}

int path_rm_path(path p) {
    char *pathPath = path_get_path(p.name);

    if (file_exists(pathPath) == true) {
        remove_file(pathPath);
    } else {
        e_error(UNEXISTING_PATH_E);
    }
}