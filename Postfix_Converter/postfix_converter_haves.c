#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100


// stack�� �⺻ Ʋ�� ����ü�� �������� ����
typedef struct StackType
{
	int arr[SIZE];
	int top;
} StackType;


void init(StackType* s);
int is_empty(StackType* s);
int is_full(StackType* s);
void push(StackType* s, int value);
int pop(StackType* s);
int top_value(StackType* s);
int cmpr_str(int value, const char str[]);
void print_intstack(StackType* s);



int main()
{
	StackType operator_stack; // �����ڸ� ������ stack
	StackType result_stack; // postfix���� ��� �� (���)
	char input_equation[SIZE] = "a+b*(u*k+(c+e)*d)/i+k";
	int i;


	// stack�� ��� �ʱ�ȭ
	init(&operator_stack);
	init(&result_stack);


	for (i = 0; i < strlen(input_equation); i++)
	{
		// '+', '-' �� Ȯ���ϸ� ��ȣ ���� ���� '+', '-' �� ������ �����ڸ� ��� ��ȯ
		if (input_equation[i] == '+' || input_equation[i] == '-')
		{
			// ���� top�� �ش��ϴ� ���� '(', '+', '-' �� ���Ͽ� ���� ���� ��� operator_stack�� ���� pop�Ͽ� result_stack�� push��
			while (!cmpr_str(top_value(&operator_stack), "(") && operator_stack.top != -1)
				push(&result_stack, pop(&operator_stack));
			push(&operator_stack, input_equation[i]);
		}
		// '*', '/', '(' �� Ȯ���ϸ� operator_stack�� �׾Ƶ�
		else if (input_equation[i] == '*' || input_equation[i] == '/')
		{
			while (!cmpr_str(top_value(&operator_stack), "(+-"))
				push(&result_stack, pop(&operator_stack));
			push(&operator_stack, input_equation[i]);
		}

		else if (input_equation[i] == '(') push(&operator_stack, input_equation[i]);

		// ')' �� Ȯ���ϸ� �ռ� '('�� operator_stack���� Ȯ���ϱ� �������� ��� �����ڸ� result_stack�� ������� push ��
		else if (input_equation[i] == ')')
		{
			while (1)
			{
				// '(' �� Ȯ���ϸ� �ش� ���� pop�ϰ� �ݺ��� ������(��ȣ�� ����)
				if (top_value(&operator_stack) == '(')
				{
					pop(&operator_stack);
					break;
				}
				push(&result_stack, pop(&operator_stack));
			}
		}
		// �����ڰ� �ƴ� ��� ���ڴ� �ٷ� result_stack�� push��
		else
			push(&result_stack, input_equation[i]);
		// input_equation�� ��� ���ڸ� Ȯ���� �ڿ��� operator_stack�� �����ִ� ��� �����ڸ� result_stack�� push��
		if (i == strlen(input_equation) - 1)
			while (operator_stack.top >= 0) push(&result_stack, pop(&operator_stack));
	}

	print_intstack(&result_stack);

	return 0;
}

// stack�� top���� -1���� �ʱ�ȭ
void init(StackType* s)
{
	//s->arr[1] = '\0'; //-> ���ڿ��� ����ϱ� ���� NULL�� �߰�
	s->top = -1;

	return;
}

// �迭�� ����ִ��� Ȯ��
int is_empty(StackType* s)
{
	if (s->top == -1) return 1;
	return 0;
}

// �迭�� ���� ���ִ��� Ȯ��
int is_full(StackType* s)
{
	if (s->top == SIZE-1) return 1;
	return 0;
}

// �迭�� ���� ���� �ʾ����� ���ο� ���� top�� ���� �� top ����
void push(StackType* s, int value)
{
	if (is_full(s) == 0)
	{
		s->arr[++(s->top)] = value;
		// s->arr[s->top] = '\0'; -> ���ڿ��� ��� �� NULL �� �ʿ��ϱ⿡ ��� ����
		return;
	}
	printf("���� �迭�� �� �������Ƿ� �� �̻� ���� ���� �� �����ϴ�.\n");
	return;
}

// �迭�� ������� ������ top ��ġ�� ���� ��ȯ�� ������ NULL�� ��ȯ �� top����
int pop(StackType* s)
{
	if (is_empty(s) == 0)
	{
		int temp = s->arr[(s->top)];
		s->arr[(s->top)--] = NULL;
		return temp;
	}
	printf("���� �迭�� �ƹ� �͵� �����Ƿ� �� �̻� ���� ���� �� �����ϴ�.\n");
	return;
}

// stack�� top�� ��ġ�� ���� ��ȯ
int top_value(StackType* s)
{
	return s->arr[s->top];
}

// ���ڿ��� �ش� ���� �ִ��� ��
int cmpr_str(int value, const char str[])
{
	int temp = 0;
	for (int i = 0; i < strlen(str); i++) if (value == str[i]) temp++;
	if (temp == 0) return 0;
	return 1;
}

// ������ �ڷḦ ��� stack�� ��� ���� ���ʴ�� ���
void print_intstack(StackType* s)
{
	for (int i = 0; i <= s->top; i++)
		printf("%c ", s->arr[i]);
	return;
}