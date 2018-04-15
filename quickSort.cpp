#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*!
 * Program testuje szybkosc dzialania sortowania "Quick Sort"
 * dla 100 tablic o losowych wartosciach
 *
 */

void quickSort( int *tab, int left, int right )
{
    int l = left;
    int r = right;
    int pivot = tab[( left + right ) / 2 ];
    do{
        while( tab[l] < pivot )
          l++;
        while( tab[r] > pivot )
          r--;
        if( l <= r ){
          swap( tab[l], tab[r] );
          l++;  r--;
        }
    }while( l <= r );

    if( left < r )
      quickSort( tab, left, r );
    if( right > l )
      quickSort( tab, l, right );
}


void print(int *arr, int size){
  for(int i =0; i<size; i++)
    cout << arr[i] << "  ";
  cout << endl;
}


void randomize(int **arr,int  size, int qnt){
  for(int j=0; j<qnt;j++){
    for(int i = 0 ; i < size ; i++)
      arr[j][i] = rand()%201-100;
  }
}


bool isSorted(int **arr, int size, int qnt){
  bool sorted = 1;
  for(int j = 0; j < size ; j++){
    for(int i =0; i<size ; i++)
      if(arr[j][i] > arr[j][i+1]) sorted = 0;
  }
  return sorted;
}

int main()
{
  srand( time( NULL ) );
  int size = 100;
  int quantity = 100;
  int ** array = new int * [quantity];
  for(int i = 0 ; i < quantity; i++)
    array[i] = new int[size];

  randomize(array,size, quantity);
  cout << "randomized!\n";

  cout << "sort test: " << isSorted(array, size-1, quantity) << endl;
  
  for(int i = 0; i<quantity; i++)
    quickSort(array[i], 0, size-1);
  cout << "sorted!\n";

  cout << "sort test: " << isSorted(array, size-1, quantity) << endl;


}
