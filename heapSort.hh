#ifndef HEAPSORT_HH
#define HEAPSORT_HH

template<typename T>
void heapify (T *tab, int heap_size, int i){
  int largest;
  T temp;
  int l=2*i, r=(2*i)+1;
  if (l<=heap_size && tab[l]>tab[i])
    largest=l;
  else largest=i;
  if (r<=heap_size && tab[r]>tab[largest])
    largest=r;
  if (largest!=i){
    temp=tab[largest];
    tab[largest]=tab[i];
    tab[i]=temp;
    heapify(tab,heap_size,largest);
  }
}

template<typename T>
void budKopiec(T *tab, int rozmiar){
  for (int i=rozmiar/2;i>0;i--)
    heapify(tab,rozmiar, i);
}

template<typename T>
void heapSort(T *tab, int rozmiar){
  int temp;
  budKopiec(tab, rozmiar);
  for (int i=rozmiar; i>0 ;i--){
    temp=tab[i];
    tab[i]=tab[0];
    tab[0]=temp;
    rozmiar--;
    heapify(tab,rozmiar,0);
  }
}


#endif
