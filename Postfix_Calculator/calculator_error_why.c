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

	char modify[SIZE] = { 0 }; // ����� 100�� stack ����
	int* count = 0;
	int is_2 = 0;
	int operand_1, operand_2, answer = 0; 

	for (int i = 0; i < SIZE; i++) {

		if (!isdigit(modify_ex[i])) { // ��ȣ��� stack�� push��
			if (is_2 == 0) push_stack(&modify, modify_ex[i], &count);
			if (is_2 == 1) {
				push_stack(&modify, modify_ex[i], &count);
				is_2 = 3;
			}
		}
		else { // ���ڶ�� stack�� push ��
			push_stack(&modify, modify_ex[i], &count);
			is_2++; // stack�� �� ���ڰ� �� ������ üũ
			if (is_2 == 2 || is_2 == 4) { // stack�� �� ���ڰ� 2����� pop �ؼ� ���
				operand_2 = pop_stack(&modify, &count) - '0'; // pop �� ���ڸ� int�� �ǿ����� 1���� ����
				operand_1 = pop_stack(&modify, &count) - '0'; // pop �� ���ڸ� int�� �ǿ����� 2���� ����
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
				is_2 = 1; // ��� �������� �ٽ� ����� ���� stack�� �ְ� �ǿ����� �� 1�� �ʱ�ȭ
				}
			}
		}
	return answer;
	}