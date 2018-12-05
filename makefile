all: yiddich.o
	gcc yiddich.o
yiddich.o: yiddich.c
	gcc -c yiddich.c
run:
	./a.out
