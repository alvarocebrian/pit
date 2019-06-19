SRCS = path.c
SRCS += ../../command.c
SRCS += ../../directory.c
SRCS += ../../../lib/array.c

INCLUDES = -I ../../
INCLUDES += -I ../../../lib/

BIN_DIRECTORY = ../../../bin
BIN = pit-path

# Debug flag
FLAGS = -g
# Use GNU extension sources flag
FLAGS += -D _GNU_SOURCE

make:
	gcc $(SRCS) $(INCLUDES) -o $(BIN_DIRECTORY)/$(BIN) $(FLAGS)