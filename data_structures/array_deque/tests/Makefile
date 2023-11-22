include flags/Makefile
outputdir=out
VPATH=$(outputdir)

run: $(outputdir)/array_deque_tests
	./$(outputdir)/array_deque_tests

build: $(outputdir)/array_deque_tests

clean:
	rm $(outputdir)/unit_testing.o
	rm $(outputdir)/array_deque.o
	rm $(outputdir)/array_deque_tests.o
	rm $(outputdir)/array_deque_tests

$(outputdir)/array_deque_tests: $(outputdir)/unit_testing.o $(outputdir)/array_deque.o $(outputdir)/array_deque_tests.o
	clang $(flags) $(outputdir)/unit_testing.o $(outputdir)/array_deque.o $(outputdir)/array_deque_tests.o -o $(outputdir)/array_deque_tests

$(outputdir)/unit_testing.o: $(CURDIR)/unit_testing/unit_testing.c out
	clang $(flags) -c $(CURDIR)/unit_testing/unit_testing.c -o $(outputdir)/unit_testing.o

$(outputdir)/array_deque.o: $(CURDIR)/data_structures/array_deque/array_deque.c out
	clang $(flags) -c $(CURDIR)/data_structures/array_deque/array_deque.c -o $(outputdir)/array_deque.o

$(outputdir)/array_deque_tests.o: $(CURDIR)/data_structures/array_deque/tests/array_deque_tests.c out
	clang $(flags) -c $(CURDIR)/data_structures/array_deque/tests/array_deque_tests.c -I data_structures/array_deque/ -I unit_testing/ -o $(outputdir)/array_deque_tests.o

out:
	mkdir -p $(outputdir)
