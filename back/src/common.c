#include "common.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

/**
 *  Return values:
 *      0 on success
 *      1 on error
 */
int print_to_file(char fileName[], char content[]) {
    FILE *file;

    if (file = fopen(fileName, "a")) {
        fputs(content, file);
        fclose(file);

        return 0;
    }

    return 1;
}

void str_concat(char* str, ...) {

}