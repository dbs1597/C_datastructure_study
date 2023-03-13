#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* NEXT;
	int value;
} NODE; // node 선언

typedef struct {
	int count;
	NODE* first;
	NODE* last;
} QUEUE;

QUEUE* create_queue();
QUEUE* Enqueue (QUEUE* queue, int dataIn);
QUEUE* Dequeue(QUEUE* queue);

QUEUE* create_queue() {

	QUEUE* queue;
	queue = (QUEUE*)malloc(sizeof(QUEUE));

	queue->count = 0;
	queue->first = NULL;
	queue->last = NULL;

	return queue;
}

QUEUE* Enqueue (QUEUE* queue, int dataIn) {

	NODE* DATA;
	DATA = (NODE*)malloc(sizeof(NODE));

	DATA->value = dataIn;
	DATA->NEXT = queue->last;

	if (queue->count == 0) {
		queue->first = DATA;
		printf("%d", queue->first->value);
	}
	else {
		queue->last->NEXT = DATA;
		printf("%d", queue->last->NEXT->value);
	}
	(queue->count)++;
	queue->last = DATA;
	
	return queue;
}

QUEUE* Dequeue(QUEUE* queue) {

	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));

	if ((queue->count)!=0) {
		temp->NEXT = queue->first->NEXT;
		temp->value = queue->first->value;
		printf("%d", temp->value);
		queue->first = temp->NEXT;
	}
	else {
		printf("더 이상 뺄 값이 없습니다.\n");
	}
	(queue->count)--;
	free(temp);

	return queue;
}

