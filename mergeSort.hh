#ifndef MERGESORT_HH
#define MERGESORT_HH

/*
template<typename T>
void merge(T * arr, int from, int mid, int to) {
  T *tmpArr = new T[(to-from+1)];
  int i = from, j = mid+1, k = 0;

  while (i <= mid && j <= to)
  {
      if (arr[j] < arr[i]){
        tmpArr[k] = arr[j];
        j++;
        } else {
          tmpArr[k] = arr[i];
          i++;
        }
    k++;
  }

  if (i <= mid) {
    while (i <= mid){
      tmpArr[k] = arr[i];
      i++;
      k++;
      }
  } else {
    while (j <= to){
      tmpArr[k] = arr[j];
      j++;
      k++;
  }
  }

  for (i = 0; i <= to-from; i++)
  arr[from+i] = tmpArr[i];

}


template<typename T>
void mergeSort(T *arr, int from, int to){
  int mid;

  if (from != to){
    mid = (from + to)/2;
    mergeSort(arr, from, mid);
    mergeSort(arr, mid+1, to);
    merge(arr, from, mid, to);
  }
}
*/

template<typename T>
void Merge(T *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k;
  T * temp = new T [high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

// A function to split array into two parts.
template<typename T>
void mergeSort(T *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

#endif
