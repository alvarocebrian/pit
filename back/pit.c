#include <stdio.h>
#include <pit.h>
#include <command/commands.h>

int main(int argc, char **argv) {
    static struct cmd_struct commands[] = {
        {"path", cmd_path },
        {"path", cmd_path }
    };

    if(argc > 1) {
        struct cmd_struct *command = getCommand(argv[1], (struct cmd_struct**) (&commands));
        if(command) {
            argc -= 2;
            argv += 2;
            int errno = command->run(argc, argv);

            return errno;
        }
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
        "\tpath    Define paths for use inside pit\n"
    );
}


struct cmd_struct *getCommand(const char s[], struct cmd_struct **commands)
{
    int i;
    printf("%d\n",ARRAY_SIZE(commands) );
    for (i = 0; i < ARRAY_SIZE(commands); i++) {
        struct cmd_struct *p = (*commands) + i;
        if (!strcmp(s, p->cmd))
            return p;
    };
    return NULL;
}