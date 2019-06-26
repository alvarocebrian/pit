#include "command.h"
#include "common.h"
#include "directory.h"
#include "error.h"
#include "core.h"

#include <string.h>
#include <errno.h>

int cmd_list_cmd(int argc, char **argv);
int cmd_add_cmd(int argc, char **argv);
int cmd_edit_cmd(int argc, char **argv);
int cmd_rm_cmd(int argc, char **argv);
void cmd_usage(void);

char *cmdDirPath;
#define CMD_DIR "cmd"


// Subcommands
static cmd subcommands[] = {
    {"list", cmd_list_cmd},
    {"add", cmd_add_cmd},
    {"edit", cmd_edit_cmd},
    {"rm", cmd_rm_cmd},
    {0}
};

int main(int argc, char **argv) {
    if (--argc) {
        cmd *subcommand = getCommand((++argv)[0], subcommands);
        if (subcommand && init()) {
            subcommand->run(--argc, ++argv);

            return errno;
        }
        error(UNKNOWN_CMD_E);

        return 0;
    }

    usage();

    return 0;
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
            char *openCmd;
            asprintf(&openCmd, "editor %s", cmdPath);
            system(openCmd);
            chmod(cmdPath, 0750);

            return 0;
        } else {
            e_error(UNEXP_E);
        }

    } else {
        error(INVALID_NUM_ARGS_E);
        usage();

        exit(1);
    }
}

int cmd_edit_cmd(int argc, char **argv) {
    if (argc == 1) {
        char *cmdPath = cmd_get_path(argv[0]);
        if (file_exists(cmdPath) == true) {
            char *openCmd;
            asprintf(&openCmd, "editor %s", cmdPath);
            system(openCmd);

            return 0;
        } else {
            e_error(UNKNOWN_CMD_E);
        }
    } else {
        error(INVALID_NUM_ARGS_E);
        usage();

        exit(1);
    }
}

int cmd_rm_cmd(int argc, char **argv) {
    if(argc == 1) {
        char *cmdPath = cmd_get_path(argv[0]);

        if (file_exists(cmdPath) == true) {
            remove_file(cmdPath);
        } else {
            e_error(UNKNOWN_CMD_E);
        }
    } else {
        error(INVALID_NUM_ARGS_E);
        usage();

        exit(1);
    }
}


// Help functions
static void usage(void) {
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