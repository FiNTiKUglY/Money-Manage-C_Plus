all: main test

main: main.c
	gcc -pedantic -ansi -o main main.c -lm

test: main.c main_test.c
	gcc -pedantic -ansi -o test -D TESTING main.c main_test.c -lm

cleanW: 
	-del test.exe
	-del main.exe

cleanL:
	rm test -f
	rm main -f

git:
	cd ../
	git add lab3
	git commit -m "updating"
	git pull
	git push -u origin
