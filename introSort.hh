#ifndef INTROSORT_HH
#define INTROSORT_HH
/*
template<typename T>
void MaxHeapify(T* data, int heapSize, int index) {
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	if (left < heapSize && data[left] > data[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && data[right] > data[largest])
		largest = right;

	if (largest != index)
	{
		int temp = data[index];
		data[index] = data[largest];
		data[largest] = temp;

		MaxHeapify(data, heapSize, largest);
	}
}

template<typename T>
void HeapSort(T* data, int count) {
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		MaxHeapify(data, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		T temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		MaxHeapify(data, heapSize, 0);
	}
}

template<typename T>
void InsertionSort(T* data, int count) {
	for (int i = 1; i < count; ++i)
	{
		int j = i;

		while ((j > 0))
		{
			if (data[j - 1] > data[j])
			{
				data[j - 1] ^= data[j];
				data[j] ^= data[j - 1];
				data[j - 1] ^= data[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}

template<typename T>
void IntroSort(T* data, int count) {
	int partitionSize = Partition(data, 0, count - 1);

	if (partitionSize < 16)
	{
		InsertionSort(data, count);
	}
	else if (partitionSize >(2 * log(count)))
	{
		HeapSort(data, count);
	}
	else
	{
		QuickSortRecursive(data, 0, count - 1);
	}
}
*/
template <typename T>
void Hybrid_Introspective_Sort (T *Array, int N);
template <typename T>
void IntroSort (T *Array, int N, int M);
template <typename T>
int Partition (T *Array, int L, int R);
template <typename T>
void MedianOfThree (T *Array, int &L, int &R);
template <typename T>
void Exchange (T *Array, int i, int j);
template <typename T>
void Heap_Sort (T *Array, int N);
template <typename T>
void Heapify (T *Array, int i, int N);
template <typename T>
void Insertion_Sort (T *Array, int N);



template <typename T>
void Hybrid_Introspective_Sort (T *Array, int N)
{
  IntroSort(Array,N,(int)floor(2*log(N)/M_LN2));
  Insertion_Sort(Array,N);
}

template <typename T>
void IntroSort (T *Array, int N, int M)
{
  int i;
  if (M<=0)
  {
    Heap_Sort(Array,N);
    return;
  }
  i=Partition(Array,0,N);
  if (i>9)
    IntroSort(Array,i,M-1);
  if (N-1-i>9)
    IntroSort(Array+i+1,N-1-i,M-1);
}

template <typename T>
int Partition (T *Array, int L, int R)
{
  int i, j;
  if (R>=3)
    MedianOfThree(Array,L,R);
  for (i=L, j=R-2; ; )
  {
    for ( ; Array[i]<Array[R-1]; ++i);
    for ( ; j>=L && Array[j]>Array[R-1]; --j);
    if (i<j)
      Exchange(Array,i++,j--);
    else break;
  }
  Exchange(Array,i,R-1);
  return i;
}

template <typename T>
void MedianOfThree (T *Array, int &L, int &R)
{
  if (Array[++L-1]>Array[--R])
    Exchange(Array,L-1,R);
  if (Array[L-1]>Array[R/2])
    Exchange(Array,L-1,R/2);
  if (Array[R/2]>Array[R])
    Exchange(Array,R/2,R);
  Exchange(Array,R/2,R-1);
}

template <typename T>
void Exchange (T *Array, int i, int j)
{
  T temp;
  temp=Array[i];
  Array[i]=Array[j];
  Array[j]=temp;
}


template <typename T>
void Heap_Sort (T *Array, int N)
{
  int i;
  for (i=N/2; i>0; --i)
    Heapify(Array-1,i,N);
  for (i=N-1; i>0; --i)
  {
    Exchange(Array,0,i);
    Heapify(Array-1,1,i);
  }
}

template <typename T>
void Heapify (T *Array, int i, int N)
{
  int j;
  while (i<=N/2)
  {
    j=2*i;
    if (j+1<=N && Array[j+1]>Array[j])
      j=j+1;
    if (Array[i]<Array[j])
      Exchange(Array,i,j);
    else break;
    i=j;
  }
}

template <typename T>
void Insertion_Sort (T *Array, int N)
{
  int i, j;
  T temp;
  for (i=1; i<N; ++i)
  {
    temp=Array[i];
    for (j=i; j>0 && temp<Array[j-1]; --j)
      Array[j]=Array[j-1];
    Array[j]=temp;
  }
}


#endif
