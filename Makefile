all:
	g++ -std=c++11 main.cpp -Wall -I ./include

clean:
	rm -f a.out *.gch
