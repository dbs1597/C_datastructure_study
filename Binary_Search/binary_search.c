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

		//가운데 값이 탐색할 값보다 클 경우
		//right_index에 mid_index 값을 넣어줌
		if (arr[mid_index] > val) {

			if(mid_index - 1 > 0)
				right_index = mid_index - 1;

		}
		//가운데 값이 탐색값보다 작을 경우
		//left_index에 mid_index 값을 넣어줌
		else if(arr[mid_index] < val) {

			if (left_index + 1 < SIZE)
				left_index = mid_index + 1;

		}

		//탐색 완료
		else {
			printf("%d회 탐색\n", cnt);
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