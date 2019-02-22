#include <stdio.h>
#include <string.h>
#include <pit.h>

void path_usage(void);
int path_list(int argc, char **argv);
int path_add(int argc, char **argv);
int path_rm(int argc, char **argv);

int cmd_path(int argc, char **argv) {
    static struct cmd_struct subcommands[] = {
        {"list", path_list },
        {"add", path_add },
        {"rm", path_rm }
    };
    if (argc) {
        if (!strcmp("list", argv[0])){
            printf("list");
        } else if (!strcmp("add", argv[0])) {
            printf("add");
                    } else if (!strcmp("rm", argv[0])) {
            printf("rm");
        }
    }


        path_usage();

        return 0;
}


int path_list(int argc, char **argv) {

};

int path_add(int argc, char **argv) {

}

int path_rm(int argc, char **argv) {

}

void path_usage(void) {
    fprintf(stderr,
        "usage: pit path <options>\n"
        "\n"
        "The path command let define some paths for pit\n"
        "\n"
        "<options>\n"
        "\tlist                    List all paths defined\n"
        "\tadd <path_name> <path>  Add a new path to pit\n"
        "\trm <path_name>          Removes the path defined as <path_name>\n"
    );
}