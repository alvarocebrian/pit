void e_error(const char error[]);

#define debug(message) fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, message);

#define error(message) fprintf(stderr, "%s\n", message);
#define e_error(message) error(message); exit(1);