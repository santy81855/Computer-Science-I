#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printArr(int *, int);
void selectionSort(int *, int);
void bubbleSort(int *, int);
void mergeSort(int *, int);
void insertionSort(int *, int);
void swap(int *, int *);

int main()
{
	int arr[20];
	for (int i = 0; i < 20; i++)
	{
		if (!(i % 2)) //if even
		{
			arr[i] = i + 11;
		}
		else
		{
			arr[i] = i;
		}
	}

	printArr(arr, 20);

	//selection sort
	//selectionSort2(arr, 20);
	//bubbleSort(arr, 20);
	//insertionSort(arr, 20);
	reverseMergeSort(arr, 20);

	printArr(arr, 20);

	return 0;
}

void insertionSort(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		//move until the beginning if necessary
		for (int j = i; j > 0; j--)
		{
			//compare
			if (arr[j] < arr[j - 1])
				swap(arr + j, arr + j - 1); //swap them
			else
				break; //if it is in order then break
		}
	}
}

void merge(int arr[], int l, int m, int r)
{
	// get the sizes of the left and right array
	int n1 = m - l + 1;
	int n2 = r - m;
	
	// create the temp arrays
	int * L = (int *) malloc(n1*sizeof(int));
	int * r = (int *) malloc(n2*sizeof(int));
	
	// copy the data to temp arrays L[] and R[]
	for(int i = 0; i < n1; i++)
		L[i] = arr[l+i];
	for(int i = 0; i < n2; i++)
		R[i] = arr[m+1+i];
	// merge the temp arrays back into arr[l...r]
	int i = 0;
	int j = 0;
	int k = l;
	while(i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] + R[j];
			j++;
		}
		k++;
	}
	
	// copy the remaining elements of L[], if there are any
	while(i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	// copy remaining elements of R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    // get mid point
    int m = (l + r)/2;

    // sort each half
    // sort the left side first
    mergeSort(arr, l, m);
    // sort the right side
    mergeSort(arr, m+1, r);

    // join each sorted half together
    merge(arr, l, m, r);
  }
}

void printArr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d->", arr[i]);
	}
	printf("END\n");
}

void selectionSort(int *arr, int size)
{
	int min;
	int temp;

	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

void bubbleSort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
