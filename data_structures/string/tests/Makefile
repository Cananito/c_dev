# WARNING: This Makefile should be executed with `make -C data_structures/string/tests`.

run: build
	./string_tests

build: string_tests

string_tests: string_tests.c
	clang -I../ ../string_r.c string_tests.c -o string_tests

clean:
	rm -f string_tests

