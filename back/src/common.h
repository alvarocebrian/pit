extern char PIT_PATH[128];

#define PIT_DIR ".pit"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int fprint(char fileName[], char content[]);

void str_concat(char* str, ...);

/*typedef struct str_array {
    // array length
    int length;

    // array value
    void *value ;
} array;
*/