all: main test

main: main.c
	g++ -o main main.c -lm

test: main.c main_test.c
	g++ -coverage -o test -D TESTING main.cpp main_test.cpp -lm

cleanW: 
	-del test.exe
	-del main.exe

cleanL:
	rm test -f
	rm main -f

git:
	cd ../
	git add lab7
	git commit -m "updating"
	git pull
	git push
