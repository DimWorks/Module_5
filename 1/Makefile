first: main.o degree3.o degree4.o
	gcc main.o degree3.o degree4.o -o first
main.o: main.c
	gcc -c main.c
degree3.o: degree3.c
	gcc -c degree3.c
degree4.o:
	gcc -c degree4.c

second: main.o libDegree.a
	gcc main.o -L. -lDegree -o second
main.o: main.c
	gcc -c main.c
libDegree.a: degree3.o degree4.o
	ar rc libDegree.a degree3.o degree4.o
	ranlib libDegree.a
degree3.o: degree3.c
	gcc -c degree3.c
degree4.o:
	gcc -c degree4.c

