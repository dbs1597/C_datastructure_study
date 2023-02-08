#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

// Stack에 필요한 변수들을 구조체로 만듦
typedef struct StackType
{
	int arr[SIZE];
	int top;
} StackType;


void init(StackType* s);
int is_empty(StackType *s); // *s는 구조체의 포인터를 의미
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

void init(StackType* s) // 함수는 구조체의 포인터를 매개변수로 받음
{
	s->top = -1; // 배열은 인덱스가 0부터 시작하므로, top = -1이면 데이터가 없는 상황을 의미

	return;
}

// 배열이 비어있으면 (top = -1) 1 리턴, 비어있지 않은 경우 0 리턴
int is_empty(StackType* s)
{
	if (s->top == -1) return 1;
	return 0;	
}

// 배열이 차있으면 (top = SIZE - 1) 1 리턴, 차있지 않은 경우 0 리턴
int is_full(StackType* s)
{
	if (s->top == SIZE - 1) return 1;
	return 0;
}

void push(StackType* s, int value)
{
	if (is_full(s) == 0) // 꽉 차지 않은 경우 실행
	{
		s->arr[++(s->top)] = value;
		return;
	}
	printf("현재 배열이 꽉 차있으므로 더 이상 값을 넣을 수 없습니다.\n");
	return;
}

int pop(StackType* s)
{
	if (is_empty(s) == 0) // 비어있지 않은 경우 실행
		return s->arr[(s->top)--];
	printf("현재 배열에 아무 것도 없으므로 더 이상 값을 꺼낼 수 없습니다.\n");
	return ;
}