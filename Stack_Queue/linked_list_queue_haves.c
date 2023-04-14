#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// stack의 노드를 만드는 구조체
typedef struct node // 구조체 이름이 있어야 자기참조 가능
{
	int data; // 데이터를 저장
	struct node* next; // 다음 노드의 주소를 저장할 포인터
} NODE;

void push(int value);
int pop();
void queue_init();

struct node* head = NULL;
struct node* tail = NULL;


int main()
{
	queue_init();

	push(100);
	push(90);
	push(80);
	push(70);
	push(60);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	push(60);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return;
}

void push(int value)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));

	temp->next = NULL;
	temp->data = value;

	tail->next = temp;

	tail = temp;
	return;
}

int pop()
{
	NODE* del_node;
	int value;

	if (head->next == NULL)
	{
		printf("스택이 비었습니다.\n");
		exit(1);
	}

	del_node = head->next;

	value = del_node->data;

	head->next = head->next->next;

	free(del_node);
	return value;
}

void queue_init()
{
	tail = malloc(sizeof(NODE));
	head = tail;
	head->next = tail;
	return;
}