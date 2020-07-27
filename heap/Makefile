include config.mk

SRC =  ${HEAP} int_arr.c test_heap.c
OBJ = ${SRC:.c=.o}

all: options test

options:
	@echo test build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

config.h:
	cp config.def.h $@

test: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f test ${OBJ}

.PHONY: all options clean test
