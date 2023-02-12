#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pop(char* stack, int* top) {

	return stack[--*top];

}

void push(char* stack, int* top, int val) {

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

int main() {

	char stack_op[50];
	char stack_num[50];
	int op_top = 0;
	int num_top = 0;
	int i;
	char op;

	char input[50];


	strcpy(input, "a/b-c+d*e-a*c");

	for (i = 0; i < strlen(input); i++) {

		//�ǿ�����
		if (priority(input[i]) == 0) {

			push(stack_num, &num_top, input[i]);

		}
		//�ݴ� ��ȣ
		else if (input[i] == ')') {

			op = pop(stack_op, &op_top);
			while (op != '(') {
				push(stack_num, &num_top, op);
				op = pop(stack_op, &op_top);
			}

		}

		//������
		else {

			//������� �������
			//������ �켱���� �˻�
			if (op_top != 0){

				op = pop(stack_op, &op_top);
				//���ÿ� �� �ִ� �����ں��� input�� �켱������ ���� ���
				while(1) {

					if (priority(op) <= priority(input[i])) {
						if (op == '('){
							push(stack_op, &op_top, op);
							break;
						}
						else
							push(stack_num, &num_top, op);
						
					}
						
					else {
						push(stack_op, &op_top, op);
						break;
					}
					//empty stack
					if (op_top == 0) {
						break;
					}


					op = pop(stack_op, &op_top);

					
				}
				push(stack_op, &op_top, input[i]);
				
			}
			else {
				push(stack_op, &op_top, input[i]);
			}

			

		}

		
	}
	
	for (i = 0 ; i < num_top; i ++)
		printf("%c ", stack_num[i]);
	
	while (op_top != 0) {
		printf("%c ", pop(stack_op, &op_top));
	}
	return 0;
}