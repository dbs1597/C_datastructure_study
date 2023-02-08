#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int BinarySearch(int* arr, int val) {

	int left_index, right_index, mid_index;
	int cnt = 0;

	left_index = 0;
	right_index = SIZE - 1;

	mid_index = (left_index + right_index) / 2;

	while (1) {

		//��� ���� Ž���� ������ Ŭ ���
		//right_index�� mid_index ���� �־���
		if (arr[mid_index] > val) {

			if(mid_index - 1 > 0)
				right_index = mid_index - 1;

		}
		//��� ���� Ž�������� ���� ���
		//left_index�� mid_index ���� �־���
		else if(arr[mid_index] < val) {

			if (left_index + 1 < SIZE)
				left_index = mid_index + 1;

		}

		//Ž�� �Ϸ�
		else {
			printf("%dȸ Ž��\n", cnt);
			printf("index : %d val : %d\n", mid_index, val);
			return mid_index;
		}

		mid_index = (left_index + right_index) / 2;
		cnt += 1;
	}

}

int main() {

	int i, j;
	int arr[SIZE];


	for (i = 0; i < SIZE; i++) {

		arr[i] = i;

	}

	BinarySearch(arr, 902);

	return 0;
}