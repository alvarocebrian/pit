#ifndef _COMMON_H_
#define _COMMON_H_

// Pit directory name
#define PIT_DIR ".pit"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

char* rasprintf(const char *format, ...);

char* implode(const char *glue, const char **parts, int partsc);

#endif