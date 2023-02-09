#define SIZE 3
#include <stdio.h>

void push_stack(int* arr, int value, int *count);
void pop_stack(int* arr);

int main() {

	int *count = 0;

	int arr[SIZE] = { 0 };
	push_stack(arr, 1, &count);
	push_stack(arr, 5, &count);
	push_stack(arr, 5, &count);
	pop_stack(arr, &count);
	pop_stack(arr, &count);
	pop_stack(arr, &count);
	pop_stack(arr, &count);



	return;
}

void push_stack(int *arr, int value, int *count) {
	
	if (*count == SIZE) { // stack 사이즈 보다 더 많이 넣으려는 경우
		printf("stack이 가득 찼습니다.\n");
		exit(1);
	}

	arr[*count] = value;
	(*count)++;

	return;
}

void pop_stack(int* arr, int *count) {

	if (*count == 0) { // 남아있는 값이 없는데 pop 하려는 경우
		printf("stack이 비었습니다. \n");
		exit(1);
	}

		printf("pop된 값: %d\n", arr[(*count) - 1]);
		arr[(*count) - 1] = NULL;
		(*count)--;

	return;
}