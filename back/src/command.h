#ifndef _COMMAND_H_
#define _COMMAND_H_

typedef struct cmd_struct {
    // command name
    char *name;

    // function to invoque
    int (*run)(int, char **);
} cmd;

/**
 * Find and return by name a command from the list of commands
 *
 * @param s Command name to search for
 * @param commands List of commands to find into
 *
 * @return cmd|null If the command is found in the list, is returned. NULL otherwise
 */
struct cmd_struct *getCommand(const char s[], cmd *commands);

#define getCommandDir() _getCommandDir(CMD_DIR)
#define createCommandDir() _createCommandDir(CMD_DIR)

char *_getCommandDir(const char dir[]);
char *_createCommandDir(const char dir[]);

static void usage(void);

#endif

