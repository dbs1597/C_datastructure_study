#include "reference.h"

#define REPEAT 30

int* heap, heapSize;
int key = 0; // ����� ���̸� ���� 0�� �ε��� ��� x

void heapInsert(int value);
void insertSort(int idx);
int heapDelete(void);
void deleteSort(int focus);
void heapUpsize(void);
void heapDownsize(void);
void heapPrint(void);

int main() {
	int temp;

	MALLOC(heap, 2 * sizeof(int));
	heapSize = 2;

	srand(time(NULL));

	for (int i = 0; i < REPEAT; i++) {
		// 0�� �ƴϸ� ����
		temp = rand();
		if (temp % 3) {
			heapInsert(temp % 100);
			heapPrint();
		}
		// 0 �̸� ����
		else heapDelete();
	}
	free(heap);

	return;
}

// �����͸� ���� �������� �߰��� -> ���� �θ� ���� ũ�⸦ �� �� ��ȯ�ϴ� ������� �ڸ��� ã��
// �����ϴ� ��쿡�� ���� ����Ʈ���� ���� �����ϸ� ��
void heapInsert(int value) {
	// heap�� ũ�Ⱑ �������� ������ ������ ����
	if (key < heapSize - 1) {
		heap[++key] = value;
	}
	// ������ ��� ũ�� Ȯ�� �� ����
	else {
		heapUpsize();
		heap[++key] = value;
	}
	// ���Ұ� �ΰ� �̻��� ��� ������ ����
	if (key > 1) insertSort(key);
	return;
}

void insertSort(int idx) {
	int temp;
	// ����Ű�� ���Ұ� ��Ʈ��� ����
	if (idx <= 1) return;
	switch (COMPARE(heap[idx], heap[idx / 2])) {
	case -1: return;// �θ� > �ڽ� �� ��� ������ ��
	case 0: return; // �θ� == �ڽ� �� ��� ������ ��
	case 1: // �θ� < �ڽ� �� ��� �� ���� �ٲ� �� ��ͷ� ����
		SWAP(heap[idx], heap[idx / 2], temp);
		insertSort(idx / 2);
		return;
	}
}

// ���� ��Ʈ�� ������ �� ���� �������� ���� �����͸� ��Ʈ�� �־��� -> ���� �ڽ� ��� �� ū ���� ��ȯ�ϴ� ������� �ڸ��� ã��
int heapDelete(void) {
	int root;
	// heap�� ����ִ� ��� ����
	if (key < 1) {
		printf("heap empty!\n");
		return;
	}
	// heap�� ��Ʈ�� ���� �� ������ ���� ��Ʈ�� ��
	root = heap[1];
	heap[1] = heap[key--];

	// �迭�� ũ�Ⱑ ����ϴ� �������� 4�� �̻� ū ��� ũ�⸦ ����
	if (heapSize > key * 4) heapDownsize();

	// heap�� �ΰ� �̻��� �����Ͱ� �ִ� ��� ��Ʈ���� ���� �õ�
	if (key > 1) deleteSort(1);
	printf("root : %3d\n", root);
	return root;
}

void deleteSort(int idx) {
	int temp;
	// �ڽ� ��尡 �ϳ��� ���� ��� ����
	if (idx * 2 > key) {
		return;
	}
	// �ڽ� ��尡 �ϳ� ���� ���, �θ� �ڽĺ��� ���� ��� ��ȯ, ū ��� ����
	else if (idx * 2 == key) {
		if (heap[idx] < heap[idx * 2]) {
			SWAP(heap[idx], heap[idx * 2], temp);
			deleteSort(idx * 2);
			return;
		}
		return;
	}
	// ������ ���� �� �ڽ� ��庸�� ũ�ٸ� ����
	else if (heap[idx] > heap[idx * 2] && heap[idx] > heap[idx * 2 + 1]) {
		return;
	}
	// ������ ���� �Ѱ� �̻��� �ڽ� ��� ���� �۴ٸ�
	else {
		switch (COMPARE(heap[idx * 2], heap[idx * 2 + 1])) {
		case -1: // ������ ����� ���� �� ū���
			SWAP(heap[idx], heap[idx * 2 + 1], temp);
			deleteSort(idx * 2 + 1); // ������ ����� idx�� ���
			return;
		case 0: // �ڽ� ����� ���� ���� ���, ���ʰ� ��ȯ
			SWAP(heap[idx], heap[idx * 2], temp);
			deleteSort(idx * 2); // ���� ����� idx�� ���
			return;
		case 1: // ���� ����� ���� �� ū���
			SWAP(heap[idx], heap[idx * 2], temp);
			deleteSort(idx * 2); // ���� ����� idx�� ���
			return;
		}
	}
}

// ���� ũ�⸦ �ι� Ű��
// ������ ������ ������ Ű��
void heapUpsize(void) {
	REALLOC(heap, (heapSize * 2) * sizeof(int));
	heapSize *= 2;
}

// ���� ũ�⸦ �ι� ����
// ������ �����ϴ� ��� ����
void heapDownsize(void) {
	if (heapSize / 2 > 2) {
		REALLOC(heap, (heapSize / 2) * sizeof(int));
		heapSize /= 2;
	}
	else return;
}

void heapPrint(void) {
	int bi = 2;
	while (bi / 2 <= key) {
		for (int i = bi / 2; i < bi && i <= key; i++) {
			printf("%3d", heap[i]);
		}
		printf("\n");
		bi *= 2;
	}
	printf("\n\n");
}