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

void mergeSort(int *arr, int size)
{
	if (size <= 1)
		return;

	int mid = size / 2;

	int s1 = mid;
	int s2 = size - mid;

	mergeSort(arr, s1);
	mergeSort(arr + mid, s2);

	int *tmp = calloc(size, sizeof(int)); //make the temp array
	int fptr = 0;
	int bptr = mid;
	int mptr = 0;

	//loop while there are elements to move into the temp array
	for (mptr = 0; mptr < size; mptr++)
	{
		if (fptr == mid)
		{
			tmp[mptr] = arr[bptr];
			bptr++;
		}
		else if (bptr == size)
		{
			tmp[mptr] = arr[fptr];
			fptr++;
		}
		else
		{
			if (arr[fptr] < arr[bptr])
			{
				tmp[mptr] = arr[fptr];
				fptr++;
			}
			else
			{
				tmp[mptr] = arr[bptr];
				bptr++;
			}
		}
	}

	//copy the temp array into the original array
	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp[i];
	}
	//free the temp array
	free(tmp);
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
