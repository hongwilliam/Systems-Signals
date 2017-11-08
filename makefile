all: signal_testing.c
	gcc signal_testing.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out
