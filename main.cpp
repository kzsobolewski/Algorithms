#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "quickSort.hh"
#include "margeSort.hh"
#include "array.hh"



/*!
 * Program testuje szybkosc dzialania sortowania "Quick Sort"
 * dla 100 tablic o losowych wartosciach
 *
 */

template<typename T>
double sortTest(T **arr, int siz, int qnt){
  clock_t start, stop;
  double sortTime;

  start = clock();
  for(int i = 0; i<qnt; i++)
    QuickSortRecursive(arr[i], 0, siz-1);
  stop = clock();

  sortTime = (stop-start)/(double)CLOCKS_PER_SEC;
  return sortTime;
}


template<typename T>
void result(T ** array, int size, int quantity, double perc){
  double sortTime;

  randomize(array, size, quantity);
  perc = perc/100;
  sortPart(array, size, quantity, perc);
  sortTime = sortTest(array, size, quantity);
  if( isSorted(array, size - 1, quantity) ){
    perc = perc*100;
    cout << perc << "% sorted: " << sortTime << " sec\n";
  } else cerr << "error: elements not sorted\n";
}


template<typename T>
void test(T **array, int size, int quantity){
  cout << "sorting " << size << " elements\n";
  double sortTime;
/*
  randomize(array, size, quantity);
  sortTime = sortTest(array, size, quantity);
  if( isSorted(array, size - 1, quantity) ){
    cout << "All random: " << sortTime << " sec\n";
  } else cerr << "error: elements not sorted\n";


  result(array, size, quantity, 25);
  //cout << "dup\n";

  result(array, size, quantity, 50);
  result(array, size, quantity, 75);
  result(array, size, quantity, 95);
  result(array, size, quantity, 99);
*/
  result(array, size, quantity, 99.7);

  reverseAll(array, size, quantity);
  sortTime = sortTest(array, size, quantity);
  if( isSorted(array, size -1, quantity) ){
    cout << "Reversed order: " << sortTime << " sec\n";
  } else cerr << "error: elements not sorted\n";

}

int main()
{
  srand( time( NULL ) );
  int size = 10000;
  int quantity = 100;

  int ** array = new int * [quantity];
  for(int i = 0 ; i < quantity; i++)
    array[i] = new int[size];

  test(array, size, quantity);
  delete [] array;
}
