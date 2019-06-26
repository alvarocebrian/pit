#include "command.h"


static cmd subcommands[] = {
    {'download', download },
    {'remove', remove },
    {'find', find},
    0
}

int main(int argc, char **argv) {
    if (--argc) {
        cmd *subcommand = getCommand((++argv)[0], subcommands);
        if (subcommand && init()) {
            subcommand->run(--argc, ++argv);

            return errno;
        }
        error(UNKNOWN_CMD_E);
    }

    path_usage();

    return 0;
}

/**
 * Installs a new package from pit package repository
 */
int download (int argc, char **argv) {

}

/**
 * Remove an installed package
 */
int remove (int argc, char **argv) {
}

/**
 * Find information about a package
 */
int find (int argc, char **argv) {

}

