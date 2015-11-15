all: project

project: main.o exteasy.o easy.o medium.o diffi.o evil.o drawdigit.o drawboard.o playfunc.o
	gcc main.o exteasy.o easy.o medium.o diffi.o evil.o drawdigit.o drawboard.o playfunc.o -o project -lGL -lGLU -lglut

main.o: main.c
	gcc -c main.c

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

drawdigit.o: drawdigit.c
	gcc -c drawdigit.c -lGL -lGLU -lglut

drawboard.o: drawboard.c
	gcc -c drawboard.c -lGL -lGLU -lglut	

playfunc.o: playfunc.c
	gcc -c playfunc.c -lGL -lGLU -lglut

clean:
	rm *o 

