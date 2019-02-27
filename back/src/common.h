#ifndef _COMMON_H_
#define _COMMON_H_

extern char PIT_PATH[128];

#define PIT_DIR ".pit"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int fprint(char fileName[], char content[]);

void str_concat(char* str, ...);

#endif