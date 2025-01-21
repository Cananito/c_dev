# WARNING: This Makefile should be executed with `make -C data_structures/list/tests`.

run: build
	./list_tests

build: list_tests

list_tests: list_tests.c
	clang -I../ ../list.c list_tests.c -o list_tests

clean:
	rm -f list_tests

