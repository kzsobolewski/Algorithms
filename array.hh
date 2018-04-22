#ifndef ARRAY_HH
#define ARRAY_HH


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


#endif
