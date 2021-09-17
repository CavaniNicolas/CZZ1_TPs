#gcc  prog.c -o prog -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

CFLAGS = -Wall -Wextra -g -DDEBUG
LIB = -lSDL2 -lSDL2_ttf

OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

prog: $(OBJ)
	gcc -o prog $^ $(LIB)

%.o: %.c $(wildcard *.h)
	gcc -c $(CFLAGS) $<

.PHONY: clean
clean:
	rm *.o

.PHONY: mrproper
mrproper:
	rm *.o prog
