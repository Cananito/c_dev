include $(CURDIR)/flags/Makefile
VPATH=out
outputdir=out

run: build
	./$(outputdir)/array_deque_tests

build: unit_testing.o array_deque.o array_deque_tests.o 
	clang $(flags) $(outputdir)/unit_testing.o $(outputdir)/array_deque.o $(outputdir)/array_deque_tests.o -o $(outputdir)/array_deque_tests

clean:
	rm $(outputdir)/unit_testing.o
	rm $(outputdir)/array_deque.o
	rm $(outputdir)/array_deque_tests.o
	rm $(outputdir)/array_deque_tests

unit_testing.o: out
	clang $(flags) -c $(CURDIR)/unit_testing/unit_testing.c -o $(outputdir)/unit_testing.o

array_deque.o: out
	clang $(flags) -c $(CURDIR)/data_structures/array_deque/array_deque.c -o $(outputdir)/array_deque.o

array_deque_tests.o: out
	clang $(flags) -c $(CURDIR)/data_structures/array_deque/tests/array_deque_tests.c -I $(CURDIR)/data_structures/array_deque/ -I $(CURDIR)/unit_testing/ -o $(outputdir)/array_deque_tests.o

out:
	mkdir -p $(outputdir)
