#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sort_num;

void selection_sort(int* arr, int size) {
	int i;
	int j;
	int min;
	int tmp;

	min = 0;
	for (i = 0; i < size; i++) {
		min = i;
		for (j = i; j < size; j++) {
			if (*(arr+min) > *(arr+j)) {
				min = j;
			}
		}
		tmp = *(arr+i);
		*(arr+i) = *(arr+min);
		*(arr+min) = tmp;
	}
}

void bubble_sort(int* arr, int size) {
	int i;
	int j;
	int tmp;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size-i-1; j++) {
			if (*(arr+j) > *(arr+(j + 1))) {
				tmp = *(arr+j);
				*(arr+j) = *(arr+(j + 1));
				*(arr+(j + 1)) = tmp;
			}
		}
	}
}


void insertion_sort(int* arr, int size) {
	int i;
	int j;
	int tmp;

	for (i = 0; i < size-1; i++) {
		//tmp = arr[i];
		j = i + 1;
		while(j>=1&&(*(arr+j)<*(arr+(j-1)))){
			tmp = *(arr+j);
			if (*(arr+j-1) > tmp) {
				*(arr+j) = *(arr+(j - 1));
				*(arr+(j - 1)) = tmp;
			}
			j--;
		}
	}
}
void print_sort(int num) {
	switch(num) {
		case 0 : 
			printf("selection sort\n");
			break;
		case 1:
			printf("bubble sort\n");
			break;
		case 2:
			printf("insertion sort\n");
			break;
	}
}

int main() {
	int n;
	int Arr[30] = { 0 };
	int* D_Arr;
	int i;
	int size = 10;
	double start, end, t=0, gap;

	srand((unsigned int)time(NULL));
	for (sort_num = 0; sort_num < 3; ++sort_num) {
		print_sort(sort_num);
		while (size <= 200000) {
			D_Arr = (int*)malloc(sizeof(int) * size);

			for (i = 0; i < size; ++i) {
				*(D_Arr + i) = (int)rand() % size;
			}

			/*
			for (i = 0; i < size; ++i) {
				printf("%d ", *(D_Arr+i));
			}
			*/


			start = (double)clock() / CLOCKS_PER_SEC;

			//printf("\n\n\n");
			//selection_sort(D_Arr, size);
			//bubble_sort(D_Arr);
			//insertion_sort(D_Arr);
			switch (sort_num) {
			case 0:
				selection_sort(D_Arr, size);
				break;
			case 1:
				bubble_sort(D_Arr, size);
				break;
			case 2:
				insertion_sort(D_Arr, size);
				break;
			}

			end = (double)clock() / CLOCKS_PER_SEC;

			/*
			for (i = 0; i < size; ++i) {
				printf("%d ", *(D_Arr+i));
			}
			printf("\n");
			*/


			free(D_Arr);
		
			gap = (end - start) - t;
			t = end - start;
			printf("array size : %d, time taken : %lf s \t+%lf s\n", size, t, gap);

			if (size < 10000)
				size *= 10;
			else
				size += 10000;
		}
	}
	return 0;
}