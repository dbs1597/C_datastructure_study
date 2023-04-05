#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* right;
	struct node* left;
}NODE;

typedef struct node_Q {
	struct node_Q* NEXT;
	NODE* value;
} NODE_Q; // node ¼±¾ğ

typedef struct {
	int count;
	NODE_Q* first;
	NODE_Q* last;
} QUEUE;

typedef struct tree {
	NODE* root;
}TREE;

QUEUE* create_queue() {

	QUEUE* queue;
	queue = (QUEUE*)malloc(sizeof(QUEUE));

	queue->count = 0;
	queue->first = NULL;
	queue->last = NULL;

	return queue;
}

QUEUE* Enqueue(QUEUE* queue, NODE* dataIn) {

	NODE_Q* DATA;
	DATA = (NODE_Q*)malloc(sizeof(NODE_Q));

	DATA->value = dataIn;
	DATA->NEXT = queue->last;

	if (dataIn == NULL) return;

	if (queue->count == 0) {
		queue->first = DATA;
	}
	else {
		queue->last->NEXT = DATA;
	}
	(queue->count)++;
	queue->last = DATA;

	return queue;
}

NODE* Dequeue(QUEUE* queue) {

	NODE_Q* Dequeue_value;
	Dequeue_value = (NODE_Q*)malloc(sizeof(NODE_Q));

	NODE_Q* temp;
	temp = (NODE_Q*)malloc(sizeof(NODE_Q));

	if ((queue->count) != 0) {
		temp->NEXT = queue->first->NEXT;
		temp->value = queue->first->value;
		Dequeue_value->value = temp->value;
		queue->first = temp->NEXT;
		printf("%d ", Dequeue_value->value->value);
		free(temp);
	}
	else {
		return NULL;
	}
	(queue->count)--;

	return Dequeue_value->value;
}

TREE* create_tree() {

	TREE* tree;
	tree = (TREE*)malloc(sizeof(TREE));
	tree->root = NULL;

	return tree;
}

void insert_tree(TREE* tree, int dataIn) {

	NODE* DATA;
	DATA = (NODE*)malloc(sizeof(NODE));
	DATA->value = dataIn;
	DATA->left = NULL;
	DATA->right = NULL;


	if (tree->root == NULL) {
		tree->root = DATA;
		return;
	}
	
	NODE* temp;
	temp = tree->root;

	while (1) {
		if (dataIn < temp->value){
			if (temp->left == NULL) {
				temp->left = DATA;
				return;
			}
			else {
				temp = temp->left;
				continue;
			}
		}
		else {
			if (temp->right == NULL) {
				temp->right = DATA;
				return;
			}
			else {
				temp = temp->right;
				continue;
			}
		}
	}

}

void inorder_tree(NODE* root) {

	if (root->left != NULL) inorder_tree(root->left);
	printf("%d ", root->value);
	if (root->right != NULL) inorder_tree(root->right);

}

void levelorder_tree(TREE* tree) {

	NODE* Dequeue_value;
	QUEUE* queue;
	queue = create_queue();
	Enqueue(queue, tree->root);
	while (1) {
		if (Dequeue_value = Dequeue(queue)) {
			Enqueue(queue, Dequeue_value->left);
			Enqueue(queue, Dequeue_value->right);
		}
		if (Dequeue_value->left == NULL && Dequeue_value->right == NULL && queue->count == 0) return;
	}
}

int main() {

	TREE* tree;
	tree = create_tree();
	insert_tree(tree, 5);
	insert_tree(tree, 7);
	insert_tree(tree, 9);
	insert_tree(tree, 3);
	insert_tree(tree, 4);
	insert_tree(tree, 2);
	insert_tree(tree, 1);
	levelorder_tree(tree);

	return 0;
}
