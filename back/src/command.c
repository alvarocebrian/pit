#include "command.h"
#include <string.h>

struct cmd_struct *getCommand(const char s[], cmd *commands)
{
    for (cmd *p = commands; p->cmd != NULL; p++) {
        if (!strcmp(s, p->cmd))
            return p;
    };

    return NULL;
}
