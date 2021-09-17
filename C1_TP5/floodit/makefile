CDFLAGS = -Wall -Wextra -g

OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

prog: $(OBJ)
	gcc -o floodit $^ $(LIB)

%.o: %.c $(wildcard *.h)
	gcc -c $(CDFLAGS) $<

.PHONY: clean
clean:
	rm *.o

.PHONY: mrproper
mrproper:
	rm *.o floodit
