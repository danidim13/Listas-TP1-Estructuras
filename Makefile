CC = g++ -Wall -std=c++11 -g
inc = ./include

Programa: main.cpp $(wildcard $(inc)/*.h)
	$(CC) -I $(inc) main.cpp -o Programa

Etapa4: Etapa4.cpp $(wildcard $(inc)/*.h) source/Algoritmos.cpp
	$(CC) -I $(inc) source/Algoritmos.cpp Etapa4.cpp -o Etapa4


check:
	$(CC) -I $(inc) -fsyntax-only main.cpp

all: Programa Etapa4
	
test: prueba.cpp $(wildcard $(inc)/*.h) source/Algoritmos.cpp
	$(CC) -I $(inc) source/Algoritmos.cpp prueba.cpp -o test


run: all
	./Programa

clean:
	rm -f Programa $(inc)/*.gch test *.o *.out

.PHONY: check
.PHONY: all
.PHONY: clean
.PHONY: run

