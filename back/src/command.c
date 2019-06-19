#include "command.h"
#include "directory.h"
#include "error.h"
#include "common.h"

#include <string.h>
#include <stdio.h>


/**
 * Find and retrun a command by name
 */
struct cmd_struct *getCommand(const char name[], cmd *commands)
{
    for (cmd *c = commands; c->name != NULL; c++) {
        if (!strcmp(name, c->name))
            return c;
    };

    return NULL;
}

/**
 * Get command dir path
 *
 * @param dir Command directory name
 * @return commandDir Command directory path
 *
 */
char *_getCommandDir(const char dir[])
{
    char *commandDir;

    asprintf(&commandDir,"%s/%s/%s", getenv("HOME"), PIT_DIR , dir);

    return commandDir;
}

/**
 *  Create builtin command directory if it does not exists
 *
 *  @param Command directory name
 *  @return commandDir Command directory path
 */
char *_createCommandDir(const char dir[])
{
    // Get command dir
    char *commandDir = _getCommandDir(dir);

    // Create command dir if it does not exists
    if (dir_exists(commandDir) != true) {
        if(create_dir(commandDir) != 0) {
            e_error(UNEXP_E);
        }
    }

    return commandDir;
}

void runCommand(const char *command, const char **params)
{

}