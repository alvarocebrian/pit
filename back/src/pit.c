#include "pit.h"
#include "command.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

static cmd commands[] = {
    {"path", path_cmd },
    {"cmd", cmd_cmd}
};

int main(int argc, char **argv) {
    pit_init();

    if(argc > 1) {
        struct cmd_struct *command = getCommand(argv[1], commands);
        if(command) {
            argc -= 2;
            argv += 2;
            command->run(argc, argv);

            return errno;
        }
    }

    pit_usage();
}

void pit_usage(void) {

    fprintf(stderr,
        "The pit command improves commands\n"
        "\n"
        "Usage: pit <command> [<options>...]\n"
        "\n"
        "<command>\n"
        "\tpath    Define paths for use inside pit\n"
        "\tcmd     Define commands to automate actions\n"
    );
}

void pit_init(void) {
    #include "directory.h"

    init_pit_directory();
}
