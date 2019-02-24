#include "common.h"
#include "error.h"
#include "stdio.h"
#include <stdlib.h>

void e_error(const char err[]) {
    error(err);
    exit(1);
}

void error(const char err[]) {
    fprintf(stderr, "%s\n", err);
}