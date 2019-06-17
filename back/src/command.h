#ifndef _COMMAND_H_
#define _COMMAND_H_

typedef struct cmd_struct {
    // command name
    char *name;

    // function to invoque
    int (*run)(int, char **);
} cmd;

struct cmd_struct *getCommand(const char s[], cmd *commands);

#define getCommandDir() _getCommandDir(CMD_DIR)
#define createCommandDir() _createCommandDir(CMD_DIR)

char *_getCommandDir(const char dir[]);
char *_createCommandDir(const char dir[]);

#endif

