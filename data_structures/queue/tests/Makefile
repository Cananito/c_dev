include $(CURDIR)/flags/Makefile
VPATH=build
outputdir=build

run: build
	./$(outputdir)/queue_tests

build: unit_testing.o queue.o queue_tests.o 
	clang $(flags) $(outputdir)/unit_testing.o $(outputdir)/queue.o $(outputdir)/queue_tests.o -o $(outputdir)/queue_tests

clean:
	rm $(outputdir)/unit_testing.o
	rm $(outputdir)/queue.o
	rm $(outputdir)/queue_tests.o
	rm $(outputdir)/queue_tests

unit_testing.o:
	clang $(flags) -c $(CURDIR)/unit_testing/unit_testing.c -o $(outputdir)/unit_testing.o

queue.o:
	clang $(flags) -c $(CURDIR)/data_structures/queue/queue.c -o $(outputdir)/queue.o

queue_tests.o:
	clang $(flags) -c $(CURDIR)/data_structures/queue/tests/queue_tests.c -I $(CURDIR)/data_structures/queue/ -I $(CURDIR)/unit_testing/ -o $(outputdir)/queue_tests.o
