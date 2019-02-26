
#define ALIAS_DIR "alias"

void cmd_init();
void cmd_usage(void);

int cmd_list_cmd(int argc, char **argv);
int cmd_add_cmd(int argc, char **argv);
int cmd_edit_cmd(int argc, char **argv);
int cmd_rm_cmd(int argc, char **argv);

extern char cmdDirPath[128];
#define CMD_DIR "cmd"
