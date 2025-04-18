
all: mendez_p1

mendez_p1: Functions.o mendez_p1.o
	g++ Functions.o mendez_p1.o -o mendez_p1

mendez_p1.o: mendez_p1.cpp Functions.h
	g++ -c mendez_p1.cpp

Functions.o: Functions.cpp Functions.h
	g++ -c Functions.cpp

clean:
	rm -f *.o mendez_p1