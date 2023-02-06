#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arraysize 1000

void selectionSort(int[], int);
void bubbleSort(int[], int);

int main()
{

  int array[arraysize] = {0};
  int i, j, index = 0;

  srand((unsigned int)time(NULL));

  for (i = 0; i < arraysize; i++)
  {
    array[i] = (int)rand() % 10000;
  }

  selectionSort(array, arraysize);

  for (i = 0; i < arraysize; i++)
  {
    printf("%d ", array[i]);
  }

  return 0;
}

void selectionSort(int array[], int size)
{
  int i, j, index = 0;

  for (i = 0; i < size; i++)
  {
    for (j = i + 1; j < size; j++)
    {
      if (array[j] < array[index])
      {
        index = j;
      }
    }
    int temp = array[i];
    array[i] = array[index];
    array[index] = temp;
  }
}

void bubbleSort(int array[], int size)
{
  int i, j;

  for (i = 0; i < size; i++)
  {
    for (j = 1; j < size-i; j++)
    {
      if (array[j - 1] > array[j])
      {
        int temp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = temp;
      }
    }
  }
}