#include <stdio.h>
#include <stdlib.h>

void maze_search(int x, int y, int dir);
void init_step(int x, int y, int dir);
void move();

typedef struct list
{
  int x;
  int y;
  int right;
  int down;
  int left;
  int up;
  struct list *next;
} stack;

stack *top = NULL;

// [1][1]에서 [7][7] 찾기
int maze[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 1, 1, 1, 1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 0, 1, 0, 0, 0},
                  {0, 1, 0, 0, 0, 1, 0, 0, 0},
                  {0, 1, 0, 0, 0, 0, 0, 0, 0},
                  {0, 1, 0, 1, 1, 1, 0, 0, 0},
                  {0, 1, 0, 1, 0, 1, 0, 0, 0},
                  {0, 1, 1, 1, 0, 1, 1, 1, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0}};

int main()
{
  maze_search(1, 1, 0);
};

void maze_search(int x, int y, int dir) {
  if (x == 7 && y == 7) {
    return;
  };
  // [x][y]가 스택에 존재해도 return;

  init_step(x, y, dir);
  printf("[%d][%d]\n", top->x, top->y);

  if (top->down == 1) {
    top->down = 0;
    maze_search(x+1, y, 1);
  } if (top->right == 1) {
    top->right = 0;
    maze_search(x, y+1, 2);
  } if (top->up == 1) {
    top->up = 0;
    maze_search(x-1, y, 3);
  } if (top->left == 1) {
    top->left = 0;
    maze_search(x, y-1, 4);
  }
  else {
    // pop 해주기
  }
};

void init_step(int x, int y, int dir) {
  stack *element = (stack *)malloc(sizeof(stack));
  element->x = x;
  element->y = y;
  element->next = top;
  
  if (maze[x+1][y] == 1 && !(dir == 3)) {
    element->down = 1;
  } if (maze[x][y+1] == 1 && !(dir == 4)) {
    element->right = 1;
  } if (maze[x-1][y] == 1 && !(dir == 1)) {
    element->up = 1;
  } if (maze[x][y-1] == 1 && !!(dir == 2)) {
    element->left = 1;
  }

  top = element;

  // printf("%d, %d\n%d, %d, %d, %d\n", top->x, top->y, top->right, top->down, top->left, top->up);
};