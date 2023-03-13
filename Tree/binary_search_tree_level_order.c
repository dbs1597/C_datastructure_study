#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node* left;
	struct node* right;

}node;

node *root = NULL;

void push(int val) {

	node *ptr, *prev;

	if (!root){

		root = (node*)malloc(sizeof(node));
		root->val = val;

		root->left = NULL;
		root->right = NULL;
		
		return;
	}

	ptr = root;
	prev = NULL;
	while (ptr != NULL) {

		if (val < ptr->val) {
			prev = ptr;
			ptr = ptr->left;
		}

		else {
			prev = ptr;
			ptr = ptr->right;
		}
	}

	if (val < prev->val) {
		
		ptr = (node*)malloc(sizeof(node));

		ptr->val = val;
		ptr->left = NULL;
		ptr->right = NULL;

		prev->left = ptr;
	}

	else{

		ptr = (node*)malloc(sizeof(node));

		ptr->val = val;
		ptr->left = NULL;
		ptr->right = NULL;

		prev->right = ptr;
	}
}

node* node_Q[40];
int front = 0, rear = 0;

void push_q(node* ptr) {

	node_Q[++rear] = ptr;

}

node* pop_q() {

	return node_Q[++front];

}

int main() {

	FILE* fp;
	
	int input[20];
	int i, size;
	
	node* ptr;

	fp = fopen("input.txt", "r");

	size = 0;
	while (fscanf(fp, "%d ", &input[size]) != EOF) {
		size++;
	}
	
	for (i = 0; i < size; i++) {
		push(input[i]);
	}

	push_q(root);

	while (front != rear) {
		ptr = pop_q();


		printf("%d ", ptr->val);

		if (ptr->left) {
			push_q(ptr->left);
		}

		if (ptr->right) {
			push_q(ptr->right);
		}
	}

	return 0;
}