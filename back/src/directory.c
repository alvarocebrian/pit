#include "common.h"
#include "error.h"
#include "directory.h"
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

char PIT_PATH[50];
void init_pit_directory(void) {
    // Init pit path
    snprintf(PIT_PATH, 50, "%s/%s", getenv("HOME"), PIT_DIR);

    // Create pit directory if it does not exists yet
    if (dir_exists(PIT_PATH) == ENOENT) {
        if (mkdir(PIT_PATH, 0700) == -1) {
            char err[50];
            snprintf(err, 50, "Can't create pit directory at %s", PIT_PATH);
            e_error(err);
        }
    }
}

int dir_exists(const char path[]) {
    DIR* dir;
    if ((dir = opendir(path))) {
        closedir(dir);

        return 1;
    }

    return errno;
}

int file_exists(const char path[]) {
    FILE *file;
    if ((file = fopen(path, "r")))
    {
        fclose(file);

        return 1;
    }

    return errno;
}

int create_file(const char path[]) {
    FILE *file;
    if(file = fopen(path, "a+")) {
        fclose(file);

        return 1;
    }

    return errno;
}