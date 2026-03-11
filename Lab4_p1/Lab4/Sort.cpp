#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

Sort::Sort(unsigned int size, int minV, int maxV)
{
	arr = new int[size + 1];
	count = size;
	capacity = size;
	srand(time(NULL));
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = rand() % (maxV - minV + 1) + minV;
	}
}

Sort::Sort(initializer_list<int> list)
{
	count = (unsigned int)list.size();
	capacity = count;
	arr = new int[count];
	int i = 0;
	for (int val : list)
		arr[i++] = val;
}

Sort::Sort(unsigned int size, int v[])
{
	count = size;
	capacity = size;
	arr = new int[count];
	for (int i = 0; i < size; i++)
		arr[i] = v[i];
}

Sort::Sort(unsigned int size, ...)
{
	arr = new int[size + 1];
	capacity = size;
	count = size;
	va_list param;
	va_start(param, size);
	for (int i = 0; i < count; i++)
	{
		arr[i] = va_arg(param, int);
	}
	va_end(param);
}

Sort::Sort(const char* s)
{
	count = 1;
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			count++;
		i++;
	}

	capacity = count;
	arr = new int[count];
	i = 0;
	const char* p = s;
	while (*p != '\0')
	{
		arr[i++] = atoi(p);
		while (*p != '\0' && *p != ',')
			p++;
		if (*p == ',')
			p++;
	}
}

void Sort::Print()
{
	for (int i = 0; i < count; i++)
		cout << arr[i] << " ";
	cout << endl;
}


void Sort::QuickSort(bool ascendent)
{
	if (count > 1)
		myQuickSort(arr, 0, count - 1, ascendent);
}


void Sort::myQuickSort(int v[], int left, int right, bool ascendent)
{
	int i = left;
	int j = right;
	int pivot = v[(left + right) / 2];

	while (i <= j)
	{
		if(ascendent)
		{
			while (v[i] < pivot) i++;
			while (v[j] > pivot) j--;
		}
		else
		{
			while (v[i] > pivot) i++;
			while (v[j] < pivot) j--;
		}

		if (i <= j)
		{
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j) myQuickSort(v, left, j, ascendent);
	if (right > i) myQuickSort(v, i, right, ascendent);
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < count; i++)
	{
		int j = i - 1, val = arr[i];

		if (ascendent)
		{
			while (j >= 0 && arr[j] > val)
			{
				arr[j + 1] = arr[j];
				j--;
			}
		}
		else
		{
			while (j >= 0 && arr[j] < val)
			{
				arr[j + 1] = arr[j];
				j--;
			}
		}
		arr[j + 1] = val;
	}
}

void Sort::BubbleSort(bool ascendent)
{
	bool swapped;
	unsigned int n = count;

	do {
		swapped = false;

		for (unsigned int i = 0; i < n - 1; i++) {

			bool condition = ascendent ? (arr[i] > arr[i + 1]) : (arr[i] < arr[i + 1]);

			if (condition) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}
		n--;

	} while (swapped);
}


int Sort::GetElementsCount() {
	return count;
}

int Sort::GetElementFromIndex(int index) {
	if (index >= 0 && index < count) {
		return arr[index];
	}
	return -1;
}