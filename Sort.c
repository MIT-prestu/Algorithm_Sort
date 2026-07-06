#include "Sort.h"



void InserSort(int* arr, int n) {
	assert(arr);

	int i = 0;
	while (i < n - 1) {
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0) {
			if (tmp < arr[end]) {
				arr[end + 1] = arr[end];
				end--;
			}
			else {
				break;
			}
		}
		arr[end + 1] = tmp;
		i++;
	}
	
	
}



void ShellInsert(int* arr, int n) {
	assert(arr);

	int gap = n;

	while (gap > 1) {
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = arr[end + gap];

			while (end >= 0) {
				if (tmp < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else {
					break;
				}
			}

			arr[end + gap] = tmp;
		}
	}

	
	
}

void Swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void SelectInsert(int* arr, int n) {
	assert(n);

	int begin = 0, end = n - 1;

	while (begin < end) {
		int maxi = begin, mini = begin;

		for (int i = begin + 1; i <= end; i++) {

			if (arr[i] > maxi) {
				arr[maxi] = arr[begin];
			}

			if (arr[i] < mini) {
				arr[mini] = arr[i];
			}
		}

		Swap(&arr[begin], &arr[mini]);
		if (begin == maxi) {
			maxi = mini;
		}
		Swap(&arr[end], &arr[maxi]);

		begin++;
		end--;
	}
}



void AdjustDown(int* arr, int parent, int size) {
	assert(arr);

	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && arr[child] < arr[child + 1]) {
			child++;
		}

		if (arr[parent] < arr[child]) {
			Swap(&arr[parent], &arr[child]);
		}
		else {
			break;
		}

		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* arr, int n) {
	assert(arr);

	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDown(arr, i, n);
	}


	int end = n - 1;
	while (end > 0) {
		
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}


void BubbleSort(int* arr, int n) {
	assert(arr);

	for (int i = 0; i < n-1; i++) {
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}