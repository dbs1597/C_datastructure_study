#include <stdio.h>
#include <stdlib.h>


// stack�� ��带 ����� ����ü
typedef struct node // ����ü �̸��� �־�� �ڱ����� ����
{
	int data; // �����͸� ����
	struct node* next; // ���� ����� �ּҸ� ������ ������
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
		if (curr->next == NULL)	free(head); // ��常 ��ȯ�ϴ°� �³�??
		curr = curr->next;
	}

	return;
}

// ���Ḯ��Ʈ�� �������� �� �߰�
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
		printf("������ �����");
		exit(-1);
	}

	value = s->data;

	del_node = s;

	s = s->next;

	free(del_node);

	return value;
}

// stack�� top�� 0���� Ȯ��
int empty_check(NODE* s)
{
	if (s->next == NULL) return 1;
	else return 0;
}

// stack �ʱ�ȭ
void stack_init(NODE* s)
{
	s->next = NULL;
	return;
}