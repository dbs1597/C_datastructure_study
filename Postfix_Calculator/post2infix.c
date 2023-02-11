#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float pop(float* stack, int* top) {

	return stack[--*top];

}

void push(float* stack, int* top, float val) {

	stack[*top] = val;
	*top += 1;

}
int priority(char input) {

	switch (input) {

	case '(':
		return 1;
	case ')':
		return 1;
	case '/':
		return 2;
	case '*':
		return 2;
	case '+':
		return 3;
	case '-':
		return 3;

	default:
		return 0;
	}
}

float calc(float* stack_val, int* stack_top, char input) {

	float a, b;

	b = pop(stack_val, stack_top);
	a = pop(stack_val, stack_top);

	switch (input) {

	case '/':
		return a / b;
	case '*':
		return a * b;
	case '+':
		return a + b;
	case '-':
		return a - b;

	}
}

int main() {

	float stack_num[50];
	int num_top = 0;
	int i;
	char op;

	char input[50];


	strcpy(input, "12/3-45*+13*-");

	for (i = 0; i < strlen(input); i++) {

		//피연산자
		if (priority(input[i]) == 0) {

			push(stack_num, &num_top, (float)(input[i] - '0'));

		}
		//연산자
		else {

			push(stack_num, &num_top, calc(stack_num, &num_top, input[i]));
			
		}


	}
	printf("%f\n", pop(stack_num, &num_top));
	
	return 0;
}