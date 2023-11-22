include flags/Makefile
outputdir=build

run: build
	./$(outputdir)/array_deque_tests

.PHONY: build
build:
	mkdir -p $(outputdir)
	clang $(CFLAGS) -c unit_testing/unit_testing.c -o $(outputdir)/unit_testing.o
	clang $(CFLAGS) -c data_structures/array_deque/array_deque.c -o $(outputdir)/array_deque.o
	clang $(CFLAGS) -c data_structures/array_deque/tests/array_deque_tests.c -I data_structures/array_deque/ -I unit_testing/ -o $(outputdir)/array_deque_tests.o
	clang $(CFLAGS) $(outputdir)/unit_testing.o $(outputdir)/array_deque.o $(outputdir)/array_deque_tests.o -o $(outputdir)/array_deque_tests
	rm $(outputdir)/*.o

clean:
	rm -f $(outputdir)/*.o
	rm -f $(outputdir)/array_deque_tests
