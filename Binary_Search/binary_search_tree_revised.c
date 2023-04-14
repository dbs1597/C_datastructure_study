#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define QUE_SIZE 100

#define COMPARE(A, B) (((A) < (B)) ? -1 : (((A) == (B)) ? 0 : 1))

// Ʈ���� ��� ����ü ����
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} NODE;

// ť ����ü ����
typedef struct que // ����ü �̸��� �־�� �ڱ����� ����
{
	struct node* data; // Ʈ���� ��� �����͸� ����
	struct que* next; // ���� ����� �ּҸ� ������ ������
} QUE;

// Ʈ���� ���� �� ����
int init_val[] = { 5, 4, 3, 1, 7, 9, 10 };
int valCount = 0;
int valSize = sizeof(init_val) / sizeof(int);
// Ʈ���� ��Ʈ ����
NODE* root = NULL;
// ť ����
QUE* head = NULL; // ���� ������ ��
QUE* tail = NULL; // ���� ���� ��

// �Լ� ����
void treePush(void);
void treeFree(NODE* N);
int tree_search(NODE* N, int srchValue);
void treeInorder(NODE* N);
void treePreorder(NODE* N);
void treePostorder(NODE* N);
void treeLevelorder(NODE* N);
void quePush(NODE* value);
NODE* quePop(void);
void queInit(void);
int queIsempty(void);


int main() {

	treePush();
	queInit();

	treeInorder(root);
	printf("\n");
	treePreorder(root);
	printf("\n");
	treePostorder(root);
	printf("\n");
	treeLevelorder(root);
	printf("\n");

	tree_search(root, 5);
	tree_search(root, 3);
	tree_search(root, 9);
	tree_search(root, 1);
	tree_search(root, 4);
	tree_search(root, 7);
	tree_search(root, 10);
	tree_search(root, 2);

	treeFree(root);
	free(head);
	return;
}

// �迭�� �ִ� ���� Ʈ���� ����
void treePush(void) {
	NODE* tempNODE;

	// ù ���� �� root�� �޸� �Ҵ�
	if (root == NULL) {
		if (!(root = (NODE*)malloc(sizeof(NODE)))) {
			printf("Error memory allocate!\n");
			exit(1);
		}
		root->data = init_val[valCount++];
		root->left = NULL;
		root->right = NULL;
	}
	tempNODE = root;

	// �ڽ� ��带 ���� �� �ʱ�ȭ
	NODE* chdNODE = malloc(sizeof(NODE));
	if (chdNODE == NULL) {
		printf("Error memory allocate!\n");
		exit(1);
	}
	chdNODE->data = init_val[valCount];
	chdNODE->left = NULL;
	chdNODE->right = NULL;

	// tree�� NODE �߰�
	while (1) {
		if (chdNODE->data < tempNODE->data) {
			if (tempNODE->left != NULL) {
				tempNODE = tempNODE->left;
				continue;
			}
			// ������� ����� �ڸ��� NULL�� ���, ���� ����
			tempNODE->left = chdNODE;
			valCount++;
			break;
		}
		else if (tempNODE->data < chdNODE->data) {
			if (tempNODE->right != NULL) {
				tempNODE = tempNODE->right;
				continue;
			}
			tempNODE->right = chdNODE;
			valCount++;
			break;
		}
		else {
			printf("�迭�� �ߺ��� ���� �ֽ��ϴ�.\n");
			exit(3);
		}
	}
	// ���� �� ���� �����Ͱ� ���Ҵٸ� ��ͷ� ����
	if (valCount < valSize) treePush();

	return;
}

// Ʈ���� ��� node�� free
void treeFree(NODE* N) {
	NODE* focusNODE = N;

	if (focusNODE->left) {
		treeFree(focusNODE->left);
	}
	if (focusNODE->right) {
		treeFree(focusNODE->right);
	}
	free(focusNODE);
	return;
}

int tree_search(NODE* N, int srchValue) {
	NODE* focusNODE = N;
	int count = 0;

	while (1) {
		if (focusNODE == NULL) {
			printf("ã�� ���� �����ϴ�.\n");
			return;
		}
		switch (COMPARE(srchValue, focusNODE->data)) {
		case -1: {
			focusNODE = focusNODE->left;
			count++;
		}break;
		case 0: {
			printf("%d\n", count);
			return focusNODE->data;
		}
		case 1: {
			focusNODE = focusNODE->right;
			count++;
		}break;
		}
	}
}

// Ʈ���� data�� in order���·� ���
void treeInorder(NODE* N) {
	NODE* focusNODE = N;

	if (focusNODE->left) {
		treeInorder(focusNODE->left);
	}
	printf("%d ", focusNODE->data);
	if (focusNODE->right) {
		treeInorder(focusNODE->right);
	}
	return;
}

// Ʈ���� data�� pre order���·� ���
void treePreorder(NODE* N) {
	NODE* focusNODE = N;

	printf("%d ", focusNODE->data);
	if (focusNODE->left) {
		treePreorder(focusNODE->left);
	}
	if (focusNODE->right) {
		treePreorder(focusNODE->right);
	}
	return;
}

// Ʈ���� data�� post order���·� ���
void treePostorder(NODE* N) {
	NODE* focusNODE = N;

	if (focusNODE->left) {
		treePostorder(focusNODE->left);
	}
	if (focusNODE->right) {
		treePostorder(focusNODE->right);
	}
	printf("%d ", focusNODE->data);
	return;
}

void treeLevelorder(NODE* N) {
	NODE* temp;
	// ù ������ ��� que�� �ٷ� �־���
	if (N != NULL) quePush(N);

	if (temp = quePop()) {
		printf("%d ", temp->data);
		if (temp->left != NULL) quePush(temp->left);
		if (temp->right != NULL) quePush(temp->right);
		if (temp->left == NULL && temp->right == NULL && queIsempty()) return;
	}

	treeLevelorder(NULL);
	return;
}

void quePush(NODE* value) {
	QUE* tempQUE = (QUE*)malloc(sizeof(QUE));
	if (tempQUE == NULL) {
		printf("Error memory allocate!\n");
		exit(1);
	}
	tempQUE->data = value;
	tempQUE->next = NULL;

	tail->next = tempQUE;
	tail = tempQUE;

	return;
}

NODE* quePop(void) {
	QUE* delQUE = NULL;
	NODE* value = NULL;
	// ť�� ����ִ� ��� ����
	if (head->next == NULL) return NULL;
	// ������ ����� �ּҿ� ���� �޾ƿ�
	delQUE = head->next;
	value = delQUE->data;
	// ��尡 ����Ű�� �ּҸ� ����
	if (delQUE->next != NULL) head->next = delQUE->next;
	// ������ ���� pop�ϴ� ��� 
	else {
		head->next = NULL;
		tail = head;
	}
	// �޸� ��ȯ
	free(delQUE);
	return value;
}

void queInit(void) {
	head = (QUE*)malloc(sizeof(QUE));
	if (head == NULL) {
		printf("Error memory allocate!\n");
		exit(1);
	}
	head->next = NULL;
	tail = head;
	return;
}

int queIsempty(void) {
	if (head->next == NULL) return 1;
	return 0;
}