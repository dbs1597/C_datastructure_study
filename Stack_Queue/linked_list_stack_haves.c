#include <stdio.h>
#include <stdlib.h>


// stack의 노드를 만드는 구조체
typedef struct node // 구조체 이름이 있어야 자기참조 가능
{
	int data; // 데이터를 저장
	struct node* next; // 다음 노드의 주소를 저장할 포인터
} NODE;



void push(NODE* s, int value);
int pop(NODE* s);
int empty_check(NODE* s);
void stack_init(NODE* s);


int main()
{
	NODE* head = malloc(sizeof(NODE));
	
	stack_init(head);
	
	for (int i = 0; i < 10; i++) push(head, i * 10);

	for (int i = 0; i < 10; i++) printf("%d\n", pop(head));

	printf("%d\n", pop(head));

	while (head != NULL)
	{
		NODE* curr = head;
		if (curr->next == NULL)	free(head); // 헤드만 반환하는게 맞나??
		curr = curr->next;
	}

	return;
}

// 연결리스트의 마지막에 값 추가
void push(NODE* s, int value)
{
	NODE* temp = malloc(sizeof(NODE));

	temp->next = s->next;
	temp->data = s->data;

	s->next = temp;
	s->data = value;
	
	return;
}

int pop(NODE* s)
{
	NODE* del_node;
	int value;

	if (empty_check(s))
	{
		printf("스택이 비었음");
		exit(-1);
	}

	value = s->data;

	del_node = s;

	s = s->next;

	free(del_node);

	return value;
}

// stack의 top이 0인지 확인
int empty_check(NODE* s)
{
	if (s->next == NULL) return 1;
	else return 0;
}

// stack 초기화
void stack_init(NODE* s)
{
	s->next = NULL;
	return;
}