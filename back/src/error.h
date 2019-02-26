#define debug(message) fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, message)

#define error(message) fprintf(stderr, "%s\n", message)
#define e_error(message) error(message); exit(1);

#define INVALID_NUM_ARGS_E "Invalid number of arguments"