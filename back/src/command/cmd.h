#ifndef _CMD_H_
#define _CMD_H_

#include "array.h"

#define ALIAS_DIR "alias"

void cmd_init();
void cmd_usage(void);
char* cmd_get_path(char cmd[]);
array* cmd_get_all();

int cmd_list_cmd(int argc, char **argv);
int cmd_add_cmd(int argc, char **argv);
int cmd_edit_cmd(int argc, char **argv);
int cmd_rm_cmd(int argc, char **argv);

extern char cmdDirPath[128];
#define CMD_DIR "cmd"
#define UNEXISTING_CMD_E "Unexisting command"

#endif