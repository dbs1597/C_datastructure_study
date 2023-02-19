#include <stdio.h>

#define SIZE 1000

int binary_search_recursive(int target, int arr[], int low, int high)
{
  int mid = (int)((low + high) / 2);
  if (arr[mid] == target)
  {
    return mid;
  }

  if (arr[mid] < target)
  {
    return binary_search_recursive(target, arr, mid + 1, high);
  }
  else
  {
    return binary_search_recursive(target, arr, low, mid - 1);
  };
}

int main()
{
  int arr[SIZE];

  for (int i; i < SIZE; i++)
  {
    arr[i] = i;
  };

  int goal = binary_search_recursive(998, arr, 0, SIZE - 1);

  printf("arr[%d]: %d\n", goal, arr[goal]);
};