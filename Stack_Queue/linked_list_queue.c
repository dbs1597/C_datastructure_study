#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node *next;

}node;

node *head = NULL;
node *tail = NULL;

void push(val) {

	node *ptr;

	ptr = (node*)malloc(sizeof(node));
	ptr->next = NULL;
	ptr->val = val;

	if (!tail) {

		tail = ptr;
		head = ptr;

		return;
	}

	tail->next = ptr;
	tail = ptr;

	return;
}

int pop() {

	node *ptr;
	int return_val;

	if (!head) {
		printf("null ptr ");
		return NULL;
	}

	ptr = head;
	return_val = ptr->val;

	head = head->next;

	free(ptr);

	return return_val;
}

int main() {

	printf("%d\n", pop());

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());


	return 0;
}