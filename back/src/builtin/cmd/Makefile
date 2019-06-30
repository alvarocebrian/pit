CMD_SRC = cmd/cmd.c
EXEC_SRC = exec/exec.c

SRCS = core.c
SRCS += ../../command.c
SRCS += ../../directory.c
SRCS += ../../../lib/array.c
SRCS += ../../common.c

INCLUDES = -I .
INCLUDES += -I ../../
INCLUDES += -I ../../../lib/

BIN_DIRECTORY = ../../../bin
CMD_BIN = pit-cmd
EXEC_BIN = pit-exec


# Debug flag
FLAGS = -g
# Use GNU extension sources flag
FLAGS += -D _GNU_SOURCE

make:
	gcc $(CMD_SRC) $(SRCS) $(INCLUDES) -o $(BIN_DIRECTORY)/$(CMD_BIN) $(FLAGS)
	gcc $(EXEC_SRC) $(SRCS) $(INCLUDES) -o $(BIN_DIRECTORY)/$(EXEC_BIN) $(FLAGS)