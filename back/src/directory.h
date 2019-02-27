#ifndef _DIRECTORY_H
#define _DIRECTORY_H

#include "array.h"

#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>

void init_pit_directory(void);

/**
 *  @return
 *      true on dir_exists
 *      errno on error
 */
int dir_exists(const char path[]);

/**
 *  @return
 *      true on file_exists
 *      errno on error
 */
int file_exists(const char path[]);

/**
 *  @return
 *      0 on success
 *      errno on error
 */
int create_file(const char path[]);

/**
 *
 */
int printd(const char path[]);

/**
 *
 */
array* ls(const char path[]);

#define create_dir mkdir(path, mode);
#define _create_dir(path) mkdir(path, 0700)

#define remove_file(path) unlink(path)

#endif