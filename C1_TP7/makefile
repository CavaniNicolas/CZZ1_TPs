#option
CFLAGS = -Wall -Wextra -g -MMD
#LIB =

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))
DEP = $(patsubst %.o,%.d,$(OBJ))

.PHONY: all
all: bin/executable

bin/executable: $(OBJ)
	@mkdir -p $(@D)
	gcc -o $@ $^ #$(LIB)

build/%.o: src/%.c
	@mkdir -p $(@D)
	gcc -c $< $(CFLAGS) -o $@


.PHONY: docu
docu: docu/docu.o build/listechainée2.o
	gcc -o bin/docu $^
docu/docu.o: docu/docu.c src/listechainée2.h docu/docu.h
	gcc -c $< $(CFLAGS) -o $@
.PHONY: cleandocu
cleandocu:
	rm docu/docu.o docu/docu.d


.PHONY: clean
clean:
	rm -rf build

-include $(DEP)
