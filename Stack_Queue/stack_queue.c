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
	
	return arr[--*top];

}

void stack_push(int* arr, int* top, int val) {

	arr[*top] = val;

	*top += 1;

	return;
}

void stack_print(int* arr, int top) {

	int i = 0;

	for (i = 0; i < top; i++) {

		printf("%d ", arr[i]);

	}

	printf("\n");
}

void queue_print(int* arr, int front, int rear) {

	int i = 0;

	for (i = front; i < rear; i++) {

		printf("%d ", arr[i]);

	}

	printf("\n");

}

void queue_push(int* arr, int* rear, int val) {

	arr[*rear] = val;
	*rear += 1;

}

int queue_pop(int* arr, int* front) {
	int val = arr[*front];

	*front += 1;

	return val;

}

int main() {

	int arr[ARR_SIZE];
	int i, top = 20;
	int front = 0, rear = ARR_SIZE;

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


	//배열 초기화

	for (i = 0; i < ARR_SIZE; i++) {
		arr[i] = 0;
	}

	front = 0; rear = 0;

	printf("Queue\n");

	queue_print(arr, front, rear);

	queue_push(arr, &rear, 1);
	queue_push(arr, &rear, 2);
	queue_push(arr, &rear, 3);

	queue_print(arr, front, rear);

	printf("pop : %d\n", (queue_pop(arr, &front)));
	printf("pop : %d\n", (queue_pop(arr, &front)));
	printf("pop : %d\n", (queue_pop(arr, &front)));

	queue_print(arr, front, rear);

	return 0;
}