__start__: output
	./output

output : main.o
	g++ main.o -o output

main.o : main.cpp	quickSort.hh array.hh margeSort.hh
	g++ -c -Wall -std=c++11 -pedantic main.cpp

clear:
	rm -f output
