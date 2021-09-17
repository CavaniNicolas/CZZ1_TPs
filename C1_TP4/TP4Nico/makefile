# options
CFLAGS = -Wall -Wextra -g
# liste des fichiers objets
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))


all: prog
.PHONY: all

prog: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c hall_of_fame.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm *.o prog
.PHONY: clean