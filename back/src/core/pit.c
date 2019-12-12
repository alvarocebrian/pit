// Sytem Libraries
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

// Project Libraries
#include "command.h"
#include "directory.h"
#include "common.h"
#include "error.h"

#define BIN_DIR "/usr/share/pit"

// Functions
void usage(void);
void init(void);
int runModule(const char *command, const char **params, int paramsc);

/**
 * PIT entrypoint function. It is responsible for initializing the environment and run the corresponding submodule
 */
int main(int argc, const char **argv)
{
    if (--argc) {
        // Init pit
        init();

        runModule(argv[1], argv + 2, --argc);

        return 0;
    }

    usage();
}

/**
 * Prints PIT help
 */
void usage(void)
{

    fprintf(stderr,
        "The pit command improves commands\n"
        "\n"
        "Usage: pit <command> [<options>...]\n"
        "\n"
        "<command>\n"
        "\tpath     Define paths for use inside pit\n"
        "\tcmd      Define commands to automate actions\n"
        "\texec     Execute a command defined\n"
    );
}

/**
 * Startup actions before running any submodule
 */
void init(void)
{
    char *PIT_PATH = rasprintf("%s/.pit", getenv("HOME"));

    // Create pit directory if it does not exists yet
    if (dir_exists(PIT_PATH) != true) {
        if (create_dir(PIT_PATH) == -1) {
            e_error(rasprintf("Can't create pit directory at %s", PIT_PATH));
        }
    }
}

int runModule(const char *command, const char **params, int paramsc)
{
    char * execCommand;
    char *modulePath = rasprintf("%s/pit-%s", BIN_DIR, command);

    if (file_exists(modulePath) == true) {
        execCommand = rasprintf("%s %s", modulePath, implode(" ", params, paramsc));
        system(execCommand);

        return 0;
    }

    e_error("El comando no existe");
}