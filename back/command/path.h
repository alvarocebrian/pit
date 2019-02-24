#include "common.h"

typedef struct str_path {
    // path name
    char name[128];

    // path
    char path[256];
} path;

int path_list(int argc, char **argv);
int path_add(int argc, char **argv);
int path_rm(int argc, char **argv);

void path_usage(void);
array path_get(void);
void path_init(void);
void path_save(array paths);
path path_find(char name[]);

#define PATH_FILE "paths"
#define PATH_PRINT_FORMAT "%s : %s\n"