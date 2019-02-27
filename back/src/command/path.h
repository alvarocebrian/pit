#ifndef _PATH_H_
#define _PATH_H_

#include "common.h"
#include "array.h"

typedef struct str_path {
    // path name
    char name[128];

    // path
    char path[256];
} path;

int path_list_cmd(int argc, char **argv);
int path_find_cmd(int argc, char **argv);
int path_add_cmd(int argc, char **argv);
int path_edit_cmd(int argc, char **argv);
int path_rm_cmd(int argc, char **argv);

void path_usage(void);
array* path_get_all(void);
void path_init(void);
void path_save(array *paths);
path* path_find(char name[]);

extern char pathFilePath[128];
#define PATH_FILE "paths"
#define PATH_PRINT_FORMAT "%s : %s\n"

#endif