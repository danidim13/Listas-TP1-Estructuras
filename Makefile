CC = g++ -Wall -std=c++11 -g
inc = ./include

Programa: main.cpp $(wildcard $(inc)/*.h)
	$(CC) -I $(inc) main.cpp -o Programa

check:
	$(CC) -I $(inc) -fsyntax-only main.cpp

all: Programa

run: all
	./Programa

clean:
	rm -f Programa $(inc)/*.gch

.PHONY: check
.PHONY: all
.PHONY: clean
.PHONY: run

