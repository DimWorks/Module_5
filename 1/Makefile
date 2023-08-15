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
degree4.o: degree4.c
	gcc -c degree4.c

third: main.o libDegreeDyn.so
	sudo ldconfig
	gcc main.o -L. -lDegreeDyn -o third
main.o: main.c
	gcc -c main.c
libDegreeDyn.so: degree3.o degree4.o
	gcc -shared -o libDegreeDyn.so degree3.o degree4.o
degree3.o: degree3.c
	gcc -fPIC -c degree3.c
degree4.o: degree4.c
	gcc -fPIC -c degree4.c

clean: 
	rm -rf *.o *.a *.so
