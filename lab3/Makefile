all: main test

main: main.c
	gcc -pedantic -ansi -o main main.c

test: main.c main_test.c
	gcc -pedantic -ansi -o test -D TESTING main.c main_test.c

cleanW: 
	-del test.exe
	-del main.exe

cleanL:
	rm -f test
	rm -f main

git:
	cd ../
	git add lab3
	git commit -m "updating"
	git pull
	git push -u origin
