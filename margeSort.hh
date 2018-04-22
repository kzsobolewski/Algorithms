#ifndef MARGERSORT_HH
#define MARGESORT_HH

template<typename T>
void merge(T *tab, int from, int to, int mid){
  int i = from;
  int j = mid + 1;
  int k = 0;

  T * tmpArray = new T [to - from + 1];

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

#endif
