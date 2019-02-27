#include "cmd.h"
#include "command.h"
#include "common.h"
#include "directory.h"
#include "error.h"

#include <string.h>
#include <stdio.h>
#include "errno.h"

int cmd_cmd(int argc, char **argv) {
    static cmd subcommands[] = {
        {"list", cmd_list_cmd},
        {"add", cmd_add_cmd},
        {"edit", cmd_edit_cmd},
        {"rm", cmd_rm_cmd}


    };

    if (argc) {
        cmd_init();

        cmd *subcommand = getCommand(argv[0], subcommands);
        if(subcommand) {
            subcommand->run(--argc, ++argv);

            return errno;
        }
        error(UNKNOWN_CMD_E);

        return 0;
    }

    cmd_usage();

    return 0;
}

char cmdDirPath[128];
void cmd_init() {
    // Create the path for the cmd directory
    sprintf(cmdDirPath, "%s/%s", PIT_PATH, CMD_DIR);

    // Create cmd directory if it does not exists
    if (dir_exists(cmdDirPath) != true) {
        if(_create_dir(cmdDirPath) != 0) {
            e_error(UNEXP_E);
        }
    }

    // TODO Check there is an editor installed
}

//Subcommmands

int cmd_list_cmd(int argc, char **argv) {
    printd(cmdDirPath);

    return 0;
}

int cmd_add_cmd(int argc, char **argv) {
    if (argc == 1) {
        char *cmdPath = cmd_get_path(argv[0]);

        // Create the file for storing the command
        if (create_file(cmdPath) == 0) {
            char openCmd [128];
            sprintf(openCmd, "editor %s", cmdPath);
            system(openCmd);

            return errno;
        } else {
            e_error(UNEXP_E);
        }

    } else {
        error(INVALID_NUM_ARGS_E);
        cmd_usage();

        exit(1);
    }
}

int cmd_edit_cmd(int argc, char **argv) {
    if (argc == 1) {
        char *cmdPath = cmd_get_path(argv[0]);
        if (file_exists(cmdPath) == true) {
            char openCmd [128];
            sprintf(openCmd, "editor %s", cmdPath);
            system(openCmd);

            return 0;
        } else {
            e_error(UNEXISTING_CMD_E);
        }
    } else {
        error(INVALID_NUM_ARGS_E);
        cmd_usage();

        exit(1);
    }
}

int cmd_rm_cmd(int argc, char **argv) {
    if(argc == 1) {
        char *cmdPath = cmd_get_path(argv[0]);

        if (file_exists(cmdPath) == true) {
            remove_file(cmdPath);
        } else {
            e_error(UNEXISTING_CMD_E);
        }
    } else {
        error(INVALID_NUM_ARGS_E);
        cmd_usage();

        exit(1);
    }
}


// Help functions

void cmd_usage(void) {
    fprintf(stderr,
        "usage: pit cmd <options>\n"
        "\n"
        "The cmd command let define some commands\n"
        "\n"
        "<options>\n"
        "\tlist <cmd>   List all commands\n"
        "\tadd <cmd>    Add a command\n"
        "\tedit <cmd>   Edit a command\n"
        "\trm <cmd>     Remove a command\n"
    );
}

char* cmd_get_path(char cmd[]) {
    char *cmdPath;
    char * command;

    if (is_valid_filename(cmd) == true) {
        cmdPath = calloc(128, sizeof(char));

            // Todo sanitize cmd to avoid go out of the dir
            sprintf(cmdPath, "%s/%s", cmdDirPath, cmd);

            return cmdPath;
    }

    return NULL;
}

array* cmd_get_all() {
    array *cmds;

    cmds = ls(cmdDirPath);

    return cmds;
}