#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 100


float Fourcal(int oper, int x, int y);
int is_op(int c);
void push(float* stack, int* top, float value);
float pop(float* stack, int* top);


int main()
{
	float stack_res[SIZE];
	int res_top = 0;
	int temp;
	int i;

	char input[SIZE] = "1234*56+7*+*8/+9+";

	printf("%d\n", 1 + 2 * (3 * 4 + (5 + 6) * 7) / 8 + 9);

	for (i = 0; i < strlen(input); i++)
	{
		temp = input[i];

		if (is_op(temp))
		{
			push(stack_res, &res_top, Fourcal(is_op(temp), pop(stack_res, &res_top), pop(stack_res, &res_top)));
		}

		else push(stack_res, &res_top, temp - '0');
	}

	for (i = 0; i < res_top; i++)
		printf("%f", stack_res[i]);

	return 0;
}


float Fourcal(int check, int x, int y)
{
	switch (check)
	{
	case 1: return (x + y);

	case 2: return (x - y);

	case 3: return (x * y);

	case 4: return (x / y);

	default: return;
	}
}

// 연산자면 1 아니면 0을 반환
int is_op(int c)
{
	switch (c)
	{
	case '+': return 1;

	case '-': return 2;

	case '*': return 3;

	case '/': return 4;

	default: return 0;
	}
}

void push(float* stack, int* top, float value)
{
	stack[(*top)++] = value;
	return;
}

float pop(float* stack, int* top)
{
	return stack[--(*top)];
}

