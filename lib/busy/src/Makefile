CC = gcc
CFLAGS = -std=gnu99 -Wall -I ../include

libbusy.a: busy.o
	ar rcs $@ $^

.PHONY: clean
clean:
	rm -rf *.o *.a
