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


int main()
{
  srand( time( NULL ) );
  int size = 100000;
  int quantity = 100;

  cout << "\nSorting 100 arrays with " << size << " elements\n";
  int ** array = new int * [quantity];
  for(int i = 0 ; i < quantity; i++)
    array[i] = new int[size];

  randomize(array,size, quantity);
  cout << "randomized!\n";

  cout << "sort test: " << isSorted(array, size-1, quantity) << endl;

  double measuredTime;
  cout.setf(ios::fixed); //notacja zwykla, czyli nie wywali wyniku typu 1.175000e+003
  cout.precision(5); //liczba miejsc po przecinku, dokladnosc naszego wyniku
  clock_t start, stop; //inicjacja zmiennych zegarowych
  start=clock(); //zapisanie czasu startu mierzenia

    //quickSort(array[i], 0, size-1);
    for(int i = 0; i<quantity; i++)
      mergeSort(array[i], 0, size-1);

  stop=clock();//zapisanie konca mierzenia
  cout << "sorted!\n";

  cout << "sort test: " << isSorted(array, size-1, quantity) << endl;

  measuredTime=(stop-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
  cout<<"Time: "<< measuredTime << " sec"<<endl << endl;
  delete [] array;
}
