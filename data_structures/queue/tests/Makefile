include flags/Makefile
outputdir=out
VPATH=$(outputdir)

run: $(outputdir)/queue_tests
	./$(outputdir)/queue_tests

build: $(outputdir)/queue_tests

clean:
	rm $(outputdir)/unit_testing.o
	rm $(outputdir)/queue.o
	rm $(outputdir)/queue_tests.o
	rm $(outputdir)/queue_tests

$(outputdir)/queue_tests: $(outputdir)/unit_testing.o $(outputdir)/queue.o $(outputdir)/queue_tests.o
	clang $(flags) $(outputdir)/unit_testing.o $(outputdir)/queue.o $(outputdir)/queue_tests.o -o $(outputdir)/queue_tests

$(outputdir)/unit_testing.o: $(CURDIR)/unit_testing/unit_testing.c out
	clang $(flags) -c $(CURDIR)/unit_testing/unit_testing.c -o $(outputdir)/unit_testing.o

$(outputdir)/queue.o: $(CURDIR)/data_structures/queue/queue.c out
	clang $(flags) -c $(CURDIR)/data_structures/queue/queue.c -o $(outputdir)/queue.o

$(outputdir)/queue_tests.o: $(CURDIR)/data_structures/queue/tests/queue_tests.c out
	clang $(flags) -c $(CURDIR)/data_structures/queue/tests/queue_tests.c -I data_structures/queue/ -I unit_testing/ -o $(outputdir)/queue_tests.o

out:
	mkdir -p $(outputdir)
