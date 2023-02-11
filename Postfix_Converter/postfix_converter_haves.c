#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100


// stack의 기본 틀을 구조체의 형식으로 만듦
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
	StackType operator_stack; // 연산자를 보관할 stack
	StackType result_stack; // postfix형의 계산 식 (결과)
	char input_equation[SIZE] = "a+b*(u*k+(c+e)*d)/i+k";
	int i;


	// stack을 모두 초기화
	init(&operator_stack);
	init(&result_stack);


	for (i = 0; i < strlen(input_equation); i++)
	{
		// '+', '-' 을 확인하면 괄호 밖의 값과 '+', '-' 를 제외한 연산자를 모두 반환
		if (input_equation[i] == '+' || input_equation[i] == '-')
		{
			// 현재 top에 해당하는 값과 '(', '+', '-' 을 비교하여 같지 않은 경우 operator_stack의 값을 pop하여 result_stack에 push함
			while (!cmpr_str(top_value(&operator_stack), "(") && operator_stack.top != -1)
				push(&result_stack, pop(&operator_stack));
			push(&operator_stack, input_equation[i]);
		}
		// '*', '/', '(' 을 확인하면 operator_stack에 쌓아둠
		else if (input_equation[i] == '*' || input_equation[i] == '/')
		{
			while (!cmpr_str(top_value(&operator_stack), "(+-"))
				push(&result_stack, pop(&operator_stack));
			push(&operator_stack, input_equation[i]);
		}

		else if (input_equation[i] == '(') push(&operator_stack, input_equation[i]);

		// ')' 을 확인하면 앞선 '('를 operator_stack에서 확인하기 전까지의 모든 연산자를 result_stack에 순서대로 push 함
		else if (input_equation[i] == ')')
		{
			while (1)
			{
				// '(' 을 확인하면 해당 값을 pop하고 반복을 종료함(괄호를 끝냄)
				if (top_value(&operator_stack) == '(')
				{
					pop(&operator_stack);
					break;
				}
				push(&result_stack, pop(&operator_stack));
			}
		}
		// 연산자가 아닌 모든 문자는 바로 result_stack에 push함
		else
			push(&result_stack, input_equation[i]);
		// input_equation의 모든 문자를 확인한 뒤에는 operator_stack에 남아있는 모든 연산자를 result_stack에 push함
		if (i == strlen(input_equation) - 1)
			while (operator_stack.top >= 0) push(&result_stack, pop(&operator_stack));
	}

	print_intstack(&result_stack);

	return 0;
}

// stack의 top값을 -1으로 초기화
void init(StackType* s)
{
	//s->arr[1] = '\0'; //-> 문자열로 출력하기 위한 NULL값 추가
	s->top = -1;

	return;
}

// 배열이 비어있는지 확인
int is_empty(StackType* s)
{
	if (s->top == -1) return 1;
	return 0;
}

// 배열이 가득 차있는지 확인
int is_full(StackType* s)
{
	if (s->top == SIZE-1) return 1;
	return 0;
}

// 배열이 가득 차지 않았으면 새로운 값을 top에 삽입 후 top 증가
void push(StackType* s, int value)
{
	if (is_full(s) == 0)
	{
		s->arr[++(s->top)] = value;
		// s->arr[s->top] = '\0'; -> 문자열로 출력 시 NULL 값 필요하기에 계속 변경
		return;
	}
	printf("현재 배열이 꽉 차있으므로 더 이상 값을 넣을 수 없습니다.\n");
	return;
}

// 배열이 비어있지 않으면 top 위치의 값을 반환후 기존값 NULL로 변환 뒤 top감소
int pop(StackType* s)
{
	if (is_empty(s) == 0)
	{
		int temp = s->arr[(s->top)];
		s->arr[(s->top)--] = NULL;
		return temp;
	}
	printf("현재 배열에 아무 것도 없으므로 더 이상 값을 꺼낼 수 없습니다.\n");
	return;
}

// stack의 top에 위치한 값을 반환
int top_value(StackType* s)
{
	return s->arr[s->top];
}

// 문자열에 해당 값이 있는지 비교
int cmpr_str(int value, const char str[])
{
	int temp = 0;
	for (int i = 0; i < strlen(str); i++) if (value == str[i]) temp++;
	if (temp == 0) return 0;
	return 1;
}

// 정수형 자료를 담는 stack의 모든 값을 차례대로 출력
void print_intstack(StackType* s)
{
	for (int i = 0; i <= s->top; i++)
		printf("%c ", s->arr[i]);
	return;
}