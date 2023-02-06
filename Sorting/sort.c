#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 20

void arr_print(int* arr) {

	int i = 0;

	for (i = 0; i < ARR_SIZE; i++) {

		printf("%d ", arr[i]);

	}

	printf("\n");
}

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return 0;
}

void selection_sort(int* arr) {

	int i, j;
	int max;
	
	for (i = ARR_SIZE; i > 0; i--) {

		max = 0;

		for (j = 0; j < i; j++) {

			if (arr[j] > arr[max]) max = j;

		}

		swap(&arr[j-1], &arr[max]);

	}
}

void bubble_sort(int* arr) {

	int i, j;
	int max;

	for (i = ARR_SIZE - 1; i > 0 ; i--) {
		for (j = 0; j < i ; j ++){
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
}

int main() {

	int arr[ARR_SIZE];
	int i;

	//랜덤한 값으로 배열 초기화
	srand(time(NULL));

	for (i = 0; i < ARR_SIZE; i++) {

		arr[i] = rand() % 100;

	}

	//배열 출력
	arr_print(arr);

	//selection_sort(arr);
	bubble_sort(arr);

	//배열 출력
	arr_print(arr);

	return 0;
}