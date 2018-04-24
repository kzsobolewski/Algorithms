#ifndef QUICKSORT_HH
#define QUICKSORT_HH

template<typename T>
void quickSort( T *tab, int left, int right ){
    int l = left;
    int r = right;
    int size = right - left;
    int pivot = tab[rand()%size+l] ;
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
void sortPart(T **arr, int size, int qnt, double perc){
  int index = (size-1)*perc;
  for(int i = 0; i<qnt; i++){
    quickSort(arr[i],0,index);
  }
}


#endif
