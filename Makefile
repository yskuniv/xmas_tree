CC = gcc
CFLAGS = -std=gnu99 -Wall -I lib/busy/include

all: drivers lib xmas_tree_workload.out

.PHONY: drivers
drivers:
	make -C drivers

.PHONY: lib
lib:
	make -C lib

xmas_tree_workload.out: xmas_tree_workload.o utils.o
	gcc $^ -L lib/busy/lib -lpthread -lbusy -o $@

clean:
	make -C drivers clean
	make -C lib clean
	rm -rf *.o *.out
