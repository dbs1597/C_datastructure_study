#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 100


int Fourcal(int oper, int x, int y);
int is_num(int c);
void push(int* stack, int* top, int value);
int pop(int* stack, int* top);


int main()
{
	int stack_in[SIZE], stack_rst[SIZE];
	int in_top = 0, rst_top = 0;
	int temp, count = 0;
	int i = 0;

	char input[SIZE] = "1234*56+7*+*8/+9+";

	printf("%d\n", 1 + 2 * (3 * 4 + (5 + 6) * 7) / 8 + 9);

	while (i < strlen(input))
		push(stack_in, &in_top, input[i++]);

	stack_in[17] = '\0';
	stack_rst[17] = '\0';

	while (in_top > 0)
	{
		temp = pop(stack_in, &in_top);
		if (!is_num(temp))
		{
			count = 1;
			push(stack_rst, &rst_top, temp);
			continue;
		}
		else if (is_num(temp))
		{
			count++;
			if (count == 3)
			{
				temp = Fourcal(pop(stack_rst, &rst_top), temp, pop(stack_rst, &rst_top));
				push(stack_in, &in_top, temp + '0');
				while (rst_top > 0)
				{
					temp = pop(stack_rst, &rst_top);
					push(stack_in, &in_top, temp);
					if (!is_num(temp)) break;
				}
				if (in_top == 1) break;
				count = 0;
				continue;
			}
			push(stack_rst, &rst_top, temp);
			continue;
		}
	
	}
	printf("%d", pop(stack_in, &in_top) - '0');

	return 0;
}


int Fourcal(int oper, int x, int y)
{
	x -= '0';
	y -= '0';

	switch (oper)
	{
	case'+': return (x + y);
	case'-': return (x - y);
	case'*': return (x * y);
	case'/': return (x / y);
	}
}

// 숫자면 1, 아니면 0 반환
int is_num(int c)
{
	if (c >= '0')
		return 1;

	return 0;
}

void push(int* stack, int* top, int value)
{
	stack[(*top)++] = value;
	return;
}

int pop(int* stack, int* top)
{
	return stack[--(*top)];
}

