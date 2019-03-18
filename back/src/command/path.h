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
int path_init(void);
int path_save(path p);
path* path_find(char name[]);
char* path_get_path(char path[]);
int path_rm_path(path p);

extern char pathDirPath[128];
#define PATH_DIR "paths"

#define UNEXISTING_PATH_E "Unexisting path"
#define EXISTING_PATH_E  "Path already exists"

#endif