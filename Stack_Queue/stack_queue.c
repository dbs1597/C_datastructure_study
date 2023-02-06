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

	return;
}

int stack_pop(int* arr, int* top) {
	int return_val = *top;

	*top -= 1;

	return arr[return_val];

}

void stack_push(int* arr, int* top, int val) {

	arr[++*top] = val;
	

	return;
}

void stack_print(int* arr, int top) {

	int i = 0;

	for (i = 0; i <= top; i++) {

		printf("%d ", arr[i]);

	}

	printf("\n");
}

int main() {

	int arr[ARR_SIZE];
	int i, top = 19;
	int front, rear;

	//랜덤한 값으로 배열 초기화
	srand(time(NULL));

	for (i = 0; i < ARR_SIZE; i++) {

		arr[i] = rand() % 100;

	}

	//배열 출력
	stack_print(arr, top);

	printf("pop : %d\n", stack_pop(arr, &top));
	printf("pop : %d\n", stack_pop(arr, &top));
	printf("pop : %d\n", stack_pop(arr, &top));

	//배열 출력
	stack_print(arr, top);

	stack_push(arr, &top, 1111);
	stack_push(arr, &top, 1111);
	stack_push(arr, &top, 1111);

	//배열 출력
	stack_print(arr, top);

	printf("pop : %d\n", stack_pop(arr, &top));
	printf("pop : %d\n", stack_pop(arr, &top));
	printf("pop : %d\n", stack_pop(arr, &top));

	//배열 출력
	stack_print(arr, top);


	//랜덤한 값으로 배열 초기화
	srand(time(NULL));

	for (i = 0; i < ARR_SIZE; i++) {

		arr[i] = rand() % 100;

	}



	return 0;
}