#define SIZE 100

#include "stack_array.h"
#include <ctype.h>

int pre_calculator(char modify_ex[]);

int main() {

	char modify[SIZE] = { "*+**/21319+34" };
	printf("%d\n", pre_calculator(&modify));

	return 0;
}



int pre_calculator(char modify_ex[]) {

	char modify[SIZE] = { 0 }; // 사이즈가 100인 stack 생성
	int* count = 0;
	int is_2 = 0;
	int operand_1, operand_2, answer = 0; 

	for (int i = 0; i < SIZE; i++) {

		if (!isdigit(modify_ex[i])) { // 기호라면 stack에 push만
			if (is_2 == 0) push_stack(&modify, modify_ex[i], &count);
			if (is_2 == 1) {
				push_stack(&modify, modify_ex[i], &count);
				is_2 = 3;
			}
		}
		else { // 숫자라면 stack에 push 후
			push_stack(&modify, modify_ex[i], &count);
			is_2++; // stack에 들어간 숫자가 몇 개인지 체크
			if (is_2 == 2 || is_2 == 4) { // stack에 들어간 숫자가 2개라면 pop 해서 계산
				operand_2 = pop_stack(&modify, &count) - '0'; // pop 한 숫자를 int로 피연산자 1번에 대입
				operand_1 = pop_stack(&modify, &count) - '0'; // pop 한 숫자를 int로 피연산자 2번에 대입
				switch (pop_stack(&modify, &count)) {
					case '*': {
						answer = operand_1 * operand_2;
						break;
						}
					case '/': {
						answer = operand_1 / operand_2;
						break;
						}
					case '+': {
						answer = operand_1 + operand_2;
						break;
						}
					case '-': {
						answer = operand_1 - operand_2;
						break;
						}			
					} 
				push_stack(&modify, answer + '0', &count); 
				is_2 = 1; // 계산 끝냈으니 다시 계산한 값을 stack에 넣고 피연산자 수 1로 초기화
				}
			}
		}
	return answer;
	}