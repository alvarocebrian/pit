#include "command.h"
#include <string.h>

struct cmd_struct *getCommand(const char s[], cmd *commands)
{
    for (cmd *c = commands; c->name != NULL; c++) {
        if (!strcmp(s, c->name))
            return c;
    };

    return NULL;
}
