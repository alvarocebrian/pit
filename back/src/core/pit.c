#include "command.h"
#include "directory.h"
#include "common.h"
#include "error.h"

// Sytem Libraries
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

// Functions
void usage(void);
void init(void);


int main(int argc, char **argv) {
    if(argc > 1) {
        // Init pit
        init();
    }

    usage();
}

void usage(void) {

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

void init(void) {
    char *PIT_PATH;
    asprintf(&PIT_PATH,"%s/.pit", getenv("HOME"));

    // Create pit directory if it does not exists yet
    if (dir_exists(PIT_PATH) != true) {
        if (create_dir(PIT_PATH) == -1) {
            char err[50];
            sprintf(err, "Can't create pit directory at %s", PIT_PATH);
            e_error(err);
        }
    }
}
