CDFLAGS = -Wall -Wextra -g
LIB = -lSDL2 -lSDL2_image

OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

progSDL: $(OBJ)
	gcc -o progSDL $^ $(LIB)

%.o: %.c
	gcc -c $(CDFLAGS) $<

.PHONY: clean
clean:
	rm *.o

.PHONY: mrproper
mrproper:
	rm *.o progSDL
