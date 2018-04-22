#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*!
 * Program testuje szybkosc dzialania sortowania "Quick Sort"
 * dla 100 tablic o losowych wartosciach
 *
 */

template<typename T>
void merge(T *tab, int from, int to, int mid){
  int i = from;
  int j = mid + 1;
  int k = 0;

  T tmpArray[to - from  + 1];

  // scala 2. czesci w jedna tablice
  while(i <= mid && j<= to){
    if(tab[i] < tab[j]){
      tmpArray[k] = tab[j];
      k++; i++;
    } else {
      tmpArray[k] = tab[j];
      k++; j++;
    }
  }

  // wstawia pozostale wartosci od i do mid w tablice tmpArray
  while(i<=mid){
    tmpArray[k] = tab[i];
    k++; i++;
  }

  // wstawia pozostale wartosci of j do to w tablice tmpArray
  while(j <= to){
    tmpArray[k] = tab[j];
    k++; j++;
  }

  // przepisuje posortowane dane do oryginalnej tabicy
  for( i = from; i<= to ; i++)
    tab[i] = tmpArray[i - from];

}

template<typename T>
void mergeSort(T *tab, int from, int to){
  int mid;
  if(from < to){
      mid = (from+to)/2;

      mergeSort(tab, from, mid);
      mergeSort(tab, mid+1 , to);

      merge(tab, from, to, mid);
  }
}


template<typename T>
void quickSort( T *tab, int left, int right )
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

template<typename T>
void reverse(T *tab, int left, int right){
  if(left >= right) return;
  swap(tab[left],tab[right]);
  reverse(tab, left+1, right-1);
}

template<typename T>
void print(T *tab, int size){
  for(int i =0; i<size; i++)
    cout << tab[i] << "  ";
  cout << endl;
}

template<typename T>
void randomize(T **arr,int  size, int qnt){
  for(int j=0; j<qnt;j++){
    for(int i = 0 ; i < size ; i++)
    //  arr[j][i] = rand()%1000001-500000;
      arr[j][i] = rand()%100;
  }
}

template<typename T>
bool isSorted( T **arr, int size, int qnt){
  bool sorted = 1;
  for(int j = 0; j < qnt ; j++){
    for(int i =0; i<size ; i++)
      if(arr[j][i] > arr[j][i+1]) sorted = 0;
  }
  return sorted;
}

template<typename T>
void sortPart(T **arr, int size, int qnt, double perc){
  int index = (size-1)*perc;
  for(int i = 0; i<qnt; i++){
    quickSort(arr[i],0,index);
  }
}

int main()
{
  srand( time( NULL ) );
  int size = 10;
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
    print(array[0], size);
    for(int i = 0; i<quantity; i++)
    mergeSort(array[i], 0, size-1);
    cout << endl << endl;
    print(array[0], size);

  stop=clock();//zapisanie konca mierzenia
  cout << "sorted!\n";

  cout << "sort test: " << isSorted(array, size-1, quantity) << endl;

  measuredTime=(stop-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
  cout<<"Time: "<< measuredTime << " sec"<<endl << endl;
}
