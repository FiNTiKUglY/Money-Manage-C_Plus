all: main test

main: main.c
	gcc -pedantic -ansi -o main main.c

test: main.c main_test.c
	gcc -pedantic -ansi -o test -D TESTING main.c main_test.c

clean: 
	-del test.exe
	-del main.exe
