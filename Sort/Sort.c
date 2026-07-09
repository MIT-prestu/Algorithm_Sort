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

int GetMidNum(int* arr, int left, int right) {
	assert(arr);

	int mid = left + (right - left) / 2;

	if (arr[left] > arr[right]) {
		if (arr[right] > arr[mid]) {
			return right;
		}
		else if (arr[mid] > arr[left]){
			return left;
		}
		else {
			return mid;
		}
	}
	else{
		if (arr[left] > arr[mid]) {
			return left;
		}
		else if(arr[mid] > arr[right]) {
			return right;
		}
		else {
			return mid;
		}
	}
}




int PartSort1(int* arr, int left, int right) {
	assert(arr);

	int midi = GetMidNum(arr, left, right);
	if (midi != left) {
		Swap(&arr[midi], &arr[left]); 
	}

	int keyindex = left;
	int	begin = left;
	int end = right;

	while (begin < end) {
		while (begin < end && arr[end] >= arr[keyindex]) {
			end--;
		}

		while (begin < end && arr[begin] <= arr[keyindex]) {
			begin++;
		}

		Swap(&arr[begin], &arr[end]);
	}

	Swap(&arr[keyindex], &arr[begin]);

	return begin;
}


int PartSort2(int* arr, int left, int right) {
	assert(arr);

	int midi = GetMidNum(arr, left, right);
	if (midi != left) {
		Swap(&arr[midi], &arr[left]);
	}

	int begin = left;
	int end = right;
	int hole = begin;
	int tmp = arr[hole];

	while (begin < end) {
		while (begin < end && arr[end] >= tmp) {
			end--;
		}

		arr[hole] = arr[end];
		hole = end;

		while (begin < end && arr[begin] <= tmp) {
			begin++;
		}

		arr[hole] = arr[begin];
		hole = begin;
	}

	arr[hole] = tmp;

	return hole;

}



int PartSort3(int* arr, int left, int right) {
	assert(arr);

	int midi = GetMidNum(arr, left, right);
	if (midi != left) {
		Swap(&arr[midi], &arr[left]);
	}

	int keyindex = left;
	int tmp = arr[keyindex];

	int cur = right-1, prev = right;

	while (cur >=left) {

		if (arr[cur] > tmp && --prev != cur) {
			Swap(&arr[cur], &arr[prev]);
		}

		--cur;
	}

	--prev;
	Swap(&arr[keyindex], &arr[prev]);

	return prev;

	/*assert(arr);
	int keyi = left, prev = left, pcur = prev + 1;

	while (pcur <= right) {
		
		if (arr[pcur] < arr[keyi] && ++prev != pcur) {
			Swap(&arr[pcur], &arr[prev]);
		}
		++pcur;
	}
	Swap(&arr[keyi], &arr[prev]);

	return prev;*/
}


void QuickSort(int* arr, int left, int right) {
	assert(arr);

	if (left >= right) {
		return;
	}

	if (right - left + 1 <= 10) {
		SelectInsert(arr+left, right - left + 1);
		return;
	}

	int div = PartSort3(arr, left, right);

	QuickSort(arr, left, div - 1);
	QuickSort(arr, div + 1, right);
}


void QuickSortNOR(int* arr, int left, int right) {
	assert(arr);

	Stack st;
	STInit(&st);


	StackPush(&st, left);
	StackPush(&st, right);

	while (!IsStackEmpty(&st)) {
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);

		int div = PartSort3(arr, begin, end);

		//[begin, div-1] div [div+1, end]
		if (div + 1 < end) {
			StackPush(&st, end);
			StackPush(&st, div+1);
		}

		if (begin < div - 1) {
			StackPush(&st, div-1);
			StackPush(&st, begin);
		}

	}

	StackDestroy(&st);
}


void _MergeSort(int* arr, int left, int right, int* tmp) {
	assert(arr);

	if (left >= right) {
		return;
	}

	int div = left + (right - left) / 2;
	_MergeSort(arr, left, div, tmp);
	_MergeSort(arr, div+1, right, tmp);


	int begin1 = left, end1 = div;
	int begin2 = div+1, end2 = right;
	int i = left;

	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] <= arr[begin2]) {
			tmp[i++] = arr[begin1++];
		}
		else {
			tmp[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = arr[begin2++];
	}

	memcpy(arr + left, tmp + left, sizeof(int) * (right - left + 1));
}




void MergeSort(int* arr, int n) {
	assert(arr);

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("malloc fail");
		exit(-1);
	}

	_MergeSort(arr, 0, n - 1, tmp);

	free(tmp);
}

void MergeSortNOR(int* arr, int n) {
	assert(arr);

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("malloc fail");
		exit(-1);
	}
	
	int gap = 1;
	while (gap < n) {
		for (int i = 0; i < n; i += 2 * gap) {
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (end1 >= n) {
				break;
			}
			if (begin2 >= n) {
				break;
			}
			if (end2 >= n) {
				end2 = n - 1;
			}

			int index = i;
			while (begin1 <= end1 && begin2 <= end2) {
				if (arr[begin1] <= arr[begin2]) {
					tmp[index++] = arr[begin1++];
				}
				else {
					tmp[index++] = arr[begin2++];
				}
			}
			while (begin1 <= end1) {
				tmp[index++] = arr[begin1++];
			}
			while (begin2 <= end2) {
				tmp[index++] = arr[begin2++];
			}

			memcpy(arr + i, tmp + i, sizeof(int) * (end2 - i + 1));

		}
		gap *= 2;
	}

	free(tmp);
}


void CountSort(int* arr, int n) {
	assert(arr);

	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	int range = max - min + 1;
	int* tmp = (int*)calloc(sizeof(int) * range);
	if (tmp == NULL) {
		perror("calloc fail");
		exit(-1);
	}


	for (int i = 0; i < n; i++) {
		tmp[arr[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < range; i++) {
		while (tmp[i]--) {
			arr[index++] = i + min;
		}
	}

	free(tmp);

}