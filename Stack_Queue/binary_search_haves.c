#include <stdio.h>
#include <stdlib.h>

#include "data_structure.h"

#define NUM 5000

int binary_search(int arr[], int search_num);

int main()
{
	int arr[SIZE] = { 0 };
	int idx;

	rand_int(arr);

	arr[SIZE / 2] = NUM;

	print_array_10row(arr);

	bubble_sorting(arr);

	print_array_10row(arr);
	
	idx = binary_search(arr, NUM);

	printf("%d\n", idx);
	printf("%d\n", arr[idx]);

	return 0;
}

int binary_search(int arr[], int search_num)
{
	int right = SIZE - 1, left = 0, middle;

	if (arr[left] == search_num) return left;
	else if (arr[right] == search_num) return right;

	middle = (left + right) / 2;

	while (left != middle)
	{
		if (arr[middle] < search_num) left = middle;
		else if (arr[middle] > search_num) right = middle;
		else return middle;

		middle = (right + left) / 2;
	}

	printf("찾으려는 값이 없는 값이거나 정렬이 잘못 되었습니다.");

	return;
}