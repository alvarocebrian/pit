#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdlib.h>

#define debug(message) fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, message)

#define error(message) fprintf(stderr, "%s\n", message)
#define e_error(message) error(message); exit(1);

#define INVALID_NUM_ARGS_E "Invalid number of arguments"
#define UNEXP_E "Unexpected error"
#define UNKNOWN_CMD_E "Unknown command"

#endif