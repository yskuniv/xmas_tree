CC = gcc
CFLAGS = -std=gnu99 -Wall -I ../include

libutils.a: utils.o
	ar rcs $@ $^

.PHONY: clean
clean:
	rm -rf *.o *.a
