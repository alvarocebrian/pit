#ifndef _COMMAND_H_
#define _COMMAND_H_

typedef struct cmd_struct {
    // command name
    char *cmd;

    // function to invoque
    int (*run)(int, char **);
} cmd;

struct cmd_struct *getCommand(const char s[], cmd *commands);

int path_cmd(int argc, char **argv);
int cmd_cmd(int argc, char **argv);
int exec_cmd(int argc, char **argv);

#endif

