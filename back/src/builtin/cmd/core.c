#include "directory.h"
#include "command.h"
#include <stdio.h>

char *cmdDirPath;

const char CMD_DIR[] = "cmd";

/**
 * Return the path for a command
 *
 * @param cmd Command name
 * @return The path for a command (commands path + command)
 */
char* cmd_get_path(char cmd[]) {
    char *cmdPath;
    char * command;

    if (is_valid_filename(cmd) == true) {
        // Todo sanitize cmd to avoid go out of the dir
        asprintf(&cmdPath, "%s/%s", cmdDirPath, cmd);

            return cmdPath;
    }

    return NULL;
}

int init(void) {
    cmdDirPath = createCommandDir();

    return true;
}