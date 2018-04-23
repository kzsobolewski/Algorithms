#ifndef MARGERSORT_HH
#define MARGESORT_HH

/*
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
*/
template<typename T>
void merge(T * tablica, int start, int srodek, int koniec) {
  T *tab_pom = new T[(koniec-start+1)]; // utworzenie tablicy pomocniczej
  int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

  while (i <= srodek && j <= koniec)
  {
      if (tablica[j] < tablica[i]){
        tab_pom[k] = tablica[j];
        j++;
        } else {
          tab_pom[k] = tablica[i];
          i++;
        }
    k++;
  }

  if (i <= srodek) {
    while (i <= srodek){
      tab_pom[k] = tablica[i];
      i++;
      k++;
      }
  } else {
    while (j <= koniec){
      tab_pom[k] = tablica[j];
      j++;
      k++;
  }
  }

  for (i = 0; i <= koniec-start; i++)
  tablica[start+i] = tab_pom[i];

}


template<typename T>
void mergeSort(T *tablica, int start, int koniec){
  int srodek;

  if (start != koniec){
    srodek = (start + koniec)/2;
    mergeSort(tablica, start, srodek);
    mergeSort(tablica, srodek+1, koniec);
    merge(tablica, start, srodek, koniec);
  }
}


#endif
