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
	
	if (*count == SIZE) { // stack ������ ���� �� ���� �������� ���
		printf("stack�� ���� á���ϴ�.\n");
		exit(1);
	}

	arr[*count] = value;
	(*count)++;

	return;
}

void pop_stack(int* arr, int *count) {

	if (*count == 0) { // �����ִ� ���� ���µ� pop �Ϸ��� ���
		printf("stack�� ������ϴ�. \n");
		exit(1);
	}

		printf("pop�� ��: %d\n", arr[(*count) - 1]);
		arr[(*count) - 1] = NULL;
		(*count)--;

	return;
}