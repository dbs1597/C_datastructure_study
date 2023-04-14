#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define QUE_SIZE 100

#define COMPARE(A, B) (((A) < (B)) ? -1 : (((A) == (B)) ? 0 : 1))

// 트리의 노드 구조체 설정
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} NODE;

// 큐 구조체 설정
typedef struct que // 구조체 이름이 있어야 자기참조 가능
{
	struct node* data; // 트리의 노드 데이터를 저장
	struct que* next; // 다음 노드의 주소를 저장할 포인터
} QUE;

// 트리에 넣을 값 설정
int init_val[] = { 5, 4, 3, 1, 7, 9, 10 };
int valCount = 0;
int valSize = sizeof(init_val) / sizeof(int);
// 트리의 루트 설정
NODE* root = NULL;
// 큐 설정
QUE* head = NULL; // 값이 나오는 곳
QUE* tail = NULL; // 값이 들어가는 곳

// 함수 선언
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

// 배열에 있는 값을 트리에 삽입
void treePush(void) {
	NODE* tempNODE;

	// 첫 실행 시 root에 메모리 할당
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

	// 자식 노드를 생성 및 초기화
	NODE* chdNODE = malloc(sizeof(NODE));
	if (chdNODE == NULL) {
		printf("Error memory allocate!\n");
		exit(1);
	}
	chdNODE->data = init_val[valCount];
	chdNODE->left = NULL;
	chdNODE->right = NULL;

	// tree에 NODE 추가
	while (1) {
		if (chdNODE->data < tempNODE->data) {
			if (tempNODE->left != NULL) {
				tempNODE = tempNODE->left;
				continue;
			}
			// 만들려는 노드의 자리가 NULL인 경우, 새로 만듦
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
			printf("배열에 중복된 값이 있습니다.\n");
			exit(3);
		}
	}
	// 아직 더 넣을 데이터가 남았다면 재귀로 실행
	if (valCount < valSize) treePush();

	return;
}

// 트리의 모든 node를 free
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
			printf("찾는 값이 없습니다.\n");
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

// 트리의 data를 in order형태로 출력
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

// 트리의 data를 pre order형태로 출력
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

// 트리의 data를 post order형태로 출력
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
	// 첫 시행의 경우 que에 바로 넣어줌
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
	// 큐가 비어있는 경우 종료
	if (head->next == NULL) return NULL;
	// 삭제할 노드의 주소와 값을 받아옴
	delQUE = head->next;
	value = delQUE->data;
	// 헤드가 가리키는 주소를 변경
	if (delQUE->next != NULL) head->next = delQUE->next;
	// 마지막 값을 pop하는 경우 
	else {
		head->next = NULL;
		tail = head;
	}
	// 메모리 반환
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