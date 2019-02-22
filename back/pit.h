#include <string.h>

void usage(void);
struct cmd_struct *getCommand(const char s[], struct cmd_struct**);

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

struct cmd_struct {
    // command name
    char *cmd;

    // function to invoque
    int (*run)(int, char **);
};