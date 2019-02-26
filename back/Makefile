SRCS = $(wildcard src/*.c src/command/*.c lib/*.c)
HEADS = $(wildcard src/ src/command/ lib/)
INSTALL = /usr/local/bin/

make:
	gcc $(SRCS) -I src/ -I src/command/ -I lib/ -o bin/pit

all: make install

cleanall:
	rm bin/pit

install:
	mv bin/pit $(INSTALL)





