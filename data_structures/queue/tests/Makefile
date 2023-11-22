include flags/Makefile
outputdir=out

run: build
	./$(outputdir)/queue_tests

build:
	mkdir -p $(outputdir)
	clang $(CFLAGS) -c unit_testing/unit_testing.c -o $(outputdir)/unit_testing.o
	clang $(CFLAGS) -c data_structures/queue/queue.c -o $(outputdir)/queue.o
	clang $(CFLAGS) -c data_structures/queue/tests/queue_tests.c -I data_structures/queue/ -I unit_testing/ -o $(outputdir)/queue_tests.o
	clang $(CFLAGS) $(outputdir)/unit_testing.o $(outputdir)/queue.o $(outputdir)/queue_tests.o -o $(outputdir)/queue_tests
	rm $(outputdir)/*.o

clean:
	rm -f $(outputdir)/*.o
	rm -f $(outputdir)/queue_tests
