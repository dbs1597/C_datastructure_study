#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_arr(int* arr);
void random_arr(int* arr);
void bubble_sorting(int* arr, int num);
void selection_sorting(int* arr);


int main(void) {

	int arr[SIZE] = { 0 };
	int num = 0;
	random_arr(&arr); // 배열 초기화
	//bubble_sorting(&arr, num);
	selection_sorting(&arr);
	print_arr(&arr); // 배열 출력
	
	return 0;
}

void print_arr(int* arr) {
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) puts("");
		printf("%3d", arr[i]);
	}
	return;
}

void random_arr(int* arr) {
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 100;
	}
	return;
}

void bubble_sorting(int *arr, int num) {

	if (num == 1) { //오름차순
		for (int i = 0; i < SIZE - 1; i++){
			for (int i = 0; i < SIZE - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					int temp = 0;
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}

	if (num == 2) { //내림차순
		for (int i = 0; i < SIZE - 1; i++) {
			for (int i = 0; i < SIZE - 1; i++) {
				if (arr[i] < arr[i+1]) {
					int temp = 0;
					temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
				}
			}
		}
	}

	return;
}

void selection_sorting(int *arr) {
	
	int max_index, temp = 0;

	for (int i = SIZE - 1; i >= 0; i--) {
		max_index = 0;
		for (int j = 0; j < i + 1; j++) {
			if (arr[j] > arr[max_index]) max_index = j;
			temp = arr[max_index];
			arr[max_index] = arr[i];
			arr[i] = temp;
		}
	}

	return;
}