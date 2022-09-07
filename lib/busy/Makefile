.PHONY: default
default:
	make -C src
	mkdir -p lib
	cp src/libbusy.a lib/

.PHONY: clean
clean:
	make -C src clean
	rm -rf lib/
