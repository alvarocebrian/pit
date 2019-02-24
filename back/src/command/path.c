#include "path.h"
#include "commands.h"
#include "directory.h"
#include "error.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>

int path_cmd(int argc, char **argv) {
    static cmd subcommands[] = {
        {"list", path_list },
        {"add", path_add },
        {"rm", path_rm }
    };

    if(argc) {
        path_init();
        cmd *subcommand = getCommand(argv[0], subcommands);
        if(subcommand) {
            if (subcommand->run(--argc, ++argv));
                return 0;
        }
    }

    path_usage();
}

void path_init() {
    char pathFilePath[128]; snprintf(pathFilePath, 128, "%s/%s", PIT_PATH, PATH_FILE);

    // Create path file if it does not exists
    if(file_exists(pathFilePath) != 1) {
        if(create_file(pathFilePath) != 1) {
            e_error("Unexpected error");
        }
    }
}

/**
 * List the path pased as argv[0] or return all paths defined
 */
int path_list(int argc, char **argv) {
    array *paths = path_get_all();

    int i;
    path *p;
    for (i = 0; i < array_length(paths); i++) {
        if(argc){
            p = array_get(paths, i);
            if(!(strcmp(argv[0], p->name))) {
                printf("%s\n", p->path);
                break;
            }
        } else {
            printf("%s\t%s\n", p->name, p->path);
        }
    }

    return 0;
};

int path_add(int argc, char **argv) {
    if(argc == 2) {
        array *paths = path_get_all();

        // Create new path
        path p;
        strcpy(p.name, argv[0]);
        strcpy(p.path, argv[1]);

        // Add new path to the array
        array_push(paths, &p);

        // Store paths to file
        path_save(paths);

        return errno;

    } else {
        error("Number of arguments non valid\n");
        path_usage();
        exit(1);
    }
}

int path_rm(int argc, char **argv) {
    if(argc == 1) {
        array *paths = path_get_all();

        path *p;
        int i;
        for (i = 0; i < array_length(paths); i++) {
            p = array_get(paths, i);
            if (!(strcmp(argv[0], p->name))) {
                array_remove(paths, i);
            }
        }
    } else {
        error("Number of arguments non valid\n");
        path_usage();
        exit(1);
    }
}

void path_save(array *paths) {
    char pathFilePath[128]; snprintf(pathFilePath, 128, "%s/%s", PIT_PATH, PATH_FILE);
    FILE *file = fopen(pathFilePath, "w");

    if (file != NULL) {
        // Print number of paths
        fprintf(file, "[%d]\n", array_length(paths));

        // Print paths
        path *p;
        for (int i = 0; i < array_length(paths); ++i)
        {
            p = array_get(paths, i);
            fprintf(file, PATH_PRINT_FORMAT, p->name, p->path);
        }
    }

}

void path_usage(void) {
    fprintf(stderr,
        "usage: pit path <options>\n"
        "\n"
        "The path command let define some paths for pit\n"
        "\n"
        "<options>\n"
        "\tlist <path_name>        Return <path_name> path or list all paths defined\n"
        "\tadd <path_name> <path>  Add a new <path> to pit with name <path_name>\n"
        "\trm <path_name>          Removes the path defined as <path_name>\n"
    );
}

array* path_get_all(void) {
    FILE *file;
    int nAlias;
    array *paths;
    path *p;

    char pathFilePath[128]; snprintf(pathFilePath, 128, "%s/%s", PIT_PATH, PATH_FILE);
    file = fopen(pathFilePath, "r");
    if(file != NULL) {
        // Read number of paths and initialize array
        fscanf(file,"[%d]\n", &nAlias);
        paths = array_init_with_size(nAlias);

        // Read paths to path struct
        int i;
        path *p;
        for(i = 0; i < nAlias; i++) {
            p = malloc(sizeof(path));
            fscanf(file, PATH_PRINT_FORMAT, p->name, p->path);
            array_push(paths, p);
        }
        fclose(file);
    } else {
        e_error("Unknown error");
    }



}

path* path_find(char name[]) {
    array *paths = path_get_all();
    path *p;

    for(int i = 0; array_length(paths); i++) {
        p = array_get(paths, i);
        if (!(strcmp(name, p->name))) {
            return p;
        }
    }

    return NULL;
}
