#include <stdio.h>

#define HEAP_MAX_SIZE 100

int heap[HEAP_MAX_SIZE] = {0};
int idx = 1; //heap이 삽입될 index

void heap_insert(int value);
void heap_delete();
void printheap();

int main() {
  heap_insert(1);
  printheap();
  heap_insert(2);
  printheap();
  heap_insert(3);
  printheap();
  heap_insert(4);
  printheap();
  heap_insert(5);
  printheap();
  heap_insert(6);
  printheap();
  heap_insert(7);
  printheap();
  
  heap_delete();
  printheap();
  heap_delete();
  printheap();
  heap_delete();
  printheap();
  heap_delete();
  printheap();
  heap_delete();
  printheap();
  heap_delete();
  printheap();
  heap_delete();
  printheap();
  heap_delete();
  printheap();
}

void heap_insert(int value) {
  int pos = idx;

  heap[idx++] = value;

  while(!(pos == 1)) {
    int parent = (int)(pos/2);
    if (heap[pos] > heap[pos/2]) {
      int temp = heap[pos];
      heap[pos] = heap[parent];
      heap[parent] = temp;
    }

    pos = parent;
  }
}

void heap_delete() {
  if (idx == 1) {
    printf("Tree has no value!(Deletion not possible)\n");
    return;
  }

  int pos = 1;

  heap[pos] = heap[idx--];
  heap[idx+1] = 0;

  while(pos*2 <= idx) {
    if ((heap[pos*2] > heap[pos]) || (heap[pos*2+1] > heap[pos])) {
      int temp = heap[pos];
      if (pos*2 > idx) {
        heap[pos] = heap[pos*2];
        heap[pos*2] = temp;
        pos*=2;
      }
      else if (heap[pos*2] > heap[pos*2+1]) {
        heap[pos] = heap[pos*2];
        heap[pos*2] = temp;
        pos*=2;
      }
      else {
        int temp = heap[pos];
        heap[pos] = heap[pos*2+1];
        heap[pos*2+1] = temp;
        pos = pos*2+1;
      }
    }
    else {break;}
  }
}

void printheap() {
  if (idx == 1) {
    printf("Tree has no value!");
  }

  for(int i=1;i<idx;i++) {
    printf("%d ",heap[i]);
  }
  printf("\n");
}