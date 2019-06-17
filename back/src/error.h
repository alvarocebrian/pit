#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdlib.h>
#include <stdio.h>

// Print debug
#define debug(message) fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, message)

// Print error
#define error(message) fprintf(stderr, "%s\n", message)
#define e_error(message) error(message); exit(1);

// Error messages

// The number of arguments is not the required
#define INVALID_NUM_ARGS_E "Invalid number of arguments"

// Unknown error
#define UNEXP_E "Unexpected error"

// Builtin (sub)command does not exists
#define UNKNOWN_CMD_E "Unknown command"
#endif