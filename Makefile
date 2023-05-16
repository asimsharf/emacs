CC			=gcc
CFLAGS		=-Wall -pedantic -Werror -Wextra -std=gnu99 -Wno-format -Iinc
LDFLAGS		=
LIBS		=
OBJECTS		=$(patsubst inc/%.c, %.o, $(wildcard inc/*.c)) $(patsubst src/%.c, %.o, $(wildcard src/*.c))
MAIN		=main

all: $(MAIN)
$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/$@ $^ $(LIBS)

%.o: inc/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

gdb: $(MAIN)
	gdb ./bin/$(MAIN)

run: $(MAIN)
	./bin/$(MAIN)
	make clean

clean:
	rm -f $(OBJECTS) $(MAIN)
