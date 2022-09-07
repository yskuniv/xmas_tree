CC = gcc
CFLAGS = -std=gnu99 -Wall -I lib/busy/include -I lib/utils/include
LDFLAGS = -L lib/busy/lib -L lib/utils/lib

.PHONY: all
all: drivers lib xmas_tree_workload

.PHONY: drivers
drivers:
	make -C kernel/drivers

.PHONY: lib
lib:
	make -C lib

xmas_tree_workload: xmas_tree_workload.o
	$(CC) $(LDFLAGS) $^ -lpthread -lbusy -lutils -o $@

.PHONY: clean
clean:
	make -C kernel/drivers clean
	make -C lib clean
	rm -rf *.o xmas_tree_workload
