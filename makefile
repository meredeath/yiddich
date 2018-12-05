all: share.o
	gcc -o share.o
share.o: share.c
	gcc -c share.c
run:
	./test
