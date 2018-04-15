__start__: a.out
	./a.out

a.out : quickSort.cpp
	g++ -Wall -std=c++11 -pedantic quickSort.cpp

clear:
	rm -f a.out
