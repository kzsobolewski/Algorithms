#ifndef QUICKSORT_HH
#define QUICKSORT_HH

template<typename T>
void quickSort( T *tab, int left, int right ){
    int l = left;
    int r = right;
    int size = right - left;
  //  int pivot = tab[( left + right ) / 2 ;
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

template<typename T>
int Partition(T* data, int left, int right) {
	int pivot = data[rand()%(right-left) + left];
	T temp;
	int i = left;

	for (int j = left; j < right; ++j)
	{
		if (data[j] <= pivot)
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			i++;
		}
	}

	data[right] = data[i];
	data[i] = pivot;

	return i;
}

template<typename T>
void QuickSortRecursive(T* data, int left, int right) {
	if (left < right)
	{
		int q = Partition(data, left, right);
		QuickSortRecursive(data, left, q - 1);
		QuickSortRecursive(data, q + 1, right);
	}
}


#endif
