#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node *next;

}node;

node *top = NULL;

void push(val) {

	node *ptr;

	ptr = (node*)malloc(sizeof(node));
	ptr->next = top;
	ptr->val = val;

	if (!top) {
		top = ptr;
	}

	top = ptr;

	return;
}

int pop() {

	node *ptr;
	int return_val;

	if (!top) {
		printf("null ptr ");
		return NULL;
	}

	ptr = top;
	return_val = ptr->val;

	top = top->next;

	free(ptr);

	return return_val;
}

int main() {

	printf("%d\n", pop());

	push(1);
	push(2);
	push(3);
	push(4);
	
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	

	return 0;
}