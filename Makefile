CC			=gcc
CFLAGS		=-Wall -Wextra -Werror -pedantic -std=c11 -Wno-format -Iinc
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

run: $(MAIN)
	./bin/$(MAIN)

clean:
	rm -f $(OBJECTS) $(MAIN)