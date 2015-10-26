all: project

sudoku: sudokuz.o exteasy.o easy.o medium.o diffi.o evil.o play.o
	gcc sudokuz.o exteasy.o easy.o medium.o diffi.o evil.o play.o -o project

sudokuz.o: sudokuz.c
	gcc -c sudokuz.c

easy.o: easy.c
	gcc -c easy.c

exteasy.o: exteasy.c
	gcc -c exteasy.c

medium.o: medium.c
	gcc -c medium.c

diffi.o: diffi.c
	gcc -c diffi.c

evil.o: evil.c
	gcc -c evil.c

play.o: play.c
	gcc -c play.c

clean:
	rm *o hello

