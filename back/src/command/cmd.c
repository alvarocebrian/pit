#include "cmd.h"
#include "command.h"
#include "common.h"
#include "directory.h"
#include "error.h"
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
    sprintf(cmdDirPath, "%s/%s", PIT_PATH, CMD_DIR);

    if (dir_exists(cmdDirPath) != true) {
        if(_create_dir(cmdDirPath) != 0) {
            e_error(UNEXP_E);
        }
    }
}

//Subcommmands
int cmd_list_cmd(int argc, char **argv){}

int cmd_add_cmd(int argc, char **argv) {
    if (argc == 2) {

    } else {
        error(INVALID_NUM_ARGS_E);
        cmd_usage();

        exit(1);
    }
}

int cmd_edit_cmd(int argc, char **argv){}

int cmd_rm_cmd(int argc, char **argv){}


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