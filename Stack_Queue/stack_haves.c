#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

// Stack�� �ʿ��� �������� ����ü�� ����
typedef struct StackType
{
	int arr[SIZE];
	int top;
} StackType;


void init(StackType* s);
int is_empty(StackType *s); // *s�� ����ü�� �����͸� �ǹ�
int is_full(StackType *s);
void push(StackType* s, int value);
int pop(StackType* s);



int main()
{
	StackType stack_1;
	int enter_value = 5;

	init(&stack_1);

	push(&stack_1, 1);
	push(&stack_1, 4);
	push(&stack_1, 49);
	push(&stack_1, 2);
	push(&stack_1, 9);
	push(&stack_1, 10);
	push(&stack_1, 500);
	push(&stack_1, 5);
	for (int i = 0; i < SIZE; i++) printf("%d\t", pop(&stack_1));

	printf("\n");

	for (int i = 0; i < SIZE; i++) printf("%d\t", stack_1.arr[i]);


	return 0;
}

void init(StackType* s) // �Լ��� ����ü�� �����͸� �Ű������� ����
{
	s->top = -1; // �迭�� �ε����� 0���� �����ϹǷ�, top = -1�̸� �����Ͱ� ���� ��Ȳ�� �ǹ�

	return;
}

// �迭�� ��������� (top = -1) 1 ����, ������� ���� ��� 0 ����
int is_empty(StackType* s)
{
	if (s->top == -1) return 1;
	return 0;	
}

// �迭�� �������� (top = SIZE - 1) 1 ����, ������ ���� ��� 0 ����
int is_full(StackType* s)
{
	if (s->top == SIZE - 1) return 1;
	return 0;
}

void push(StackType* s, int value)
{
	if (is_full(s) == 0) // �� ���� ���� ��� ����
	{
		s->arr[++(s->top)] = value;
		return;
	}
	printf("���� �迭�� �� �������Ƿ� �� �̻� ���� ���� �� �����ϴ�.\n");
	return;
}

int pop(StackType* s)
{
	if (is_empty(s) == 0) // ������� ���� ��� ����
		return s->arr[(s->top)--];
	printf("���� �迭�� �ƹ� �͵� �����Ƿ� �� �̻� ���� ���� �� �����ϴ�.\n");
	return ;
}