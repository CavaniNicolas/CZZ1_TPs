#gcc  prog.c -o prog -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

CFLAGS = -Wall -Wextra -g -DDEBUG -MMD
LIB = -lSDL2 -lSDL2_ttf

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))
DEP = $(patsubst %.o,%.d,$(OBJ))

.PHONY: all
all: bin/executable

bin/executable: $(OBJ)
	@mkdir -p $(@D)
	gcc -o $@ $^ $(LIB)

build/%.o: src/%.c
	@mkdir -p $(@D)
	gcc -c $< $(CFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf build

-include $(DEP)