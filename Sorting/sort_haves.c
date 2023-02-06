#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
#define SIZE 100

void rand_arr(int arr[SIZE])
{
	int i, *arr_ptr;

	arr_ptr = arr;

	srand(time(NULL));

	for (i = 0; i < SIZE; i++)
		*(arr_ptr + i) = rand();

	return;
}


void sorting(int arr[SIZE])
{
	int temp, i, j, *arr_ptr;

	arr_ptr = arr;

	j = 0;

	for (i = 0; i < SIZE - j; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (*(arr_ptr + j) > *(arr_ptr + j + 1))
			{
				temp = *(arr_ptr + j);
				*(arr_ptr + j) = *(arr_ptr + j + 1);
				*(arr_ptr + j + 1) = temp;
			}
		}
	}
	return;
}


int main_12()
{
	int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 100, 2, 3, 200, 3, 3, 1}, i;

	//rand_arr(arr);
	
	for (i = 0; i < 100; i++)
	{
		printf("%d\t", arr[i]);
		if (i % 10 == 0)
			printf("\n");
	}
	
	sorting(arr);

	printf("\n\n");

	for (i = 0; i < 100; i++)
	{
		printf("%d\t", arr[i]);
		if (i % 10 == 0)
			printf("\n");
	}


	return 0;
}
*/