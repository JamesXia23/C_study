#include <iostream>
#include <time.h>
using namespace std;

void bubbleSort(int *array, int size);
void selectSort(int *array, int size);
void insertSort(int *array, int size);
void quickSort(int *array, int size);
void quick(int *array, int l, int r);
void mergeSort(int *array, int size);
void initArray(int *array, int size);
void showArray(int *array, int size);
void checkArray(int *array, int size);

int main(int argc, char const *argv[])
{
	int *array;
	int size;
	size_t startTime, endTime;
	cin >> size;
	array = new int[size];

	for (int i = 0; i < 5; ++i)
	{
		initArray(array, size);
		// showArray(array, size);

		startTime = clock();
		// bubbleSort(array, size);
		// selectSort(array, size);
		// insertSort(array, size);
		quickSort(array, size);
		endTime = clock();
		// showArray(array, size);
		checkArray(array, size);

		printf("sortTime%d:%dms\n", i, endTime - startTime);
	}
	
	return 0;
}

void initArray(int *array, int size)
{	 
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % (size * 5);
	}
}

void showArray(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << std::endl;
}

void checkArray(int *array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if(array[i] > array[i + 1])
			cout << "errorIndex:" << i << ",errorNum:" << array[i] << std::endl;
	}
}
void bubbleSort(int *array, int size)
{
	int temp;
	register int times = size - 1;
	for (register int i = 0; i < times; ++i)
	{
		for (register int j = 0; j < times - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
void selectSort(int *array, int size)
{
	int temp;
	register int min = 0;
	register int times = size - 1;
	for (register int i = 0; i < times; ++i)
	{
		min = i;
		for (register int j = i; j <= times; ++j)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
}
void insertSort(int *array, int size)
{
	register int temp;
	for (register int i = 0; i < size; ++i)
	{
		temp = array[i];
		for (register int j = i - 1; j >= 0; --j)
		{
			if (temp < array[j])
			{
				array[j + 1] = array[j];
			}
			else
			{
				array[j + 1] = temp;
				break;
			}
		}
	}
}
void quickSort(int *array, int size)
{
	quick(array, 0, size - 1);
}
void quick(int *array, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	register int num = array[left];
	register int l = left;
	register int r = right;
	
	while(l < r)
	{
		while(l < r && array[r] > num)
			r--;
		if (l < r)
		{
			array[l++] = array[r];
		}
		while(l < r && array[l] <= num)
			l++;
		if (l < r)
		{
			array[r--] = array[l];
		}
	}
	array[l] = num;
	// cout << key << std::endl;
	quick(array, left, l - 1);
	quick(array, r + 1, right);
}
