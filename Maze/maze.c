#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int row, col;

typedef struct xy {

	int x;
	int y;

}xy;

int maze[SIZE][SIZE];
xy path[SIZE];
path_top = 0;

void push(int x, int y) {
	path[path_top].x = x;
	path[path_top].y = y;

	path_top += 1;
}

xy pop() {
	return path[--path_top];
}

void DFS(int x_goal, int y_goal) {

	xy init, prev;
	int x, y, i;

	init = pop();

	prev = pop();
	push(prev.x, prev.y);


	x = init.x;
	y = init.y;

	if (x == x_goal & y == y_goal) {

		for (i = 0; i < path_top; i++) {
			printf("%d %d\n", path[i].x, path[i].y);
		}

		return;
	}

	//N
	if (prev.x != x - 1 || prev.y != y){
		if (maze[x - 1][y] == 1) {
			push(x, y);
			push(x - 1, y);
			DFS(x_goal, y_goal);
		}
	}
	
	//E
	if (prev.x != x || prev.y != y + 1) {
		if (maze[x][y + 1] == 1) {
			push(x, y);
			push(x, y + 1);
			DFS(x_goal, y_goal);
		}
	}

	//S
	if (prev.x != x + 1 || prev.y != y) {
		if (maze[x + 1][y] == 1) {
			push(x, y);
			push(x + 1, y);
			DFS(x_goal, y_goal);
		}
	}

	//W
	if (prev.x != x || prev.y != y - 1) {
		if (maze[x][y - 1] == 1) {
			push(x, y);
			push(x, y - 1);
			DFS(x_goal, y_goal);
		}
	}


}

int main() {

	
	int i, j;
	FILE* fp;

	//미로 읽어오기
	fp = fopen("input.txt", "r");

	fscanf(fp, "%d %d\n", &row, &col);

	for (i = 0; i <= row+1; i++) {
		for (j = 0; j <= col+1; j++) {
			fscanf(fp, "%d ", &maze[i][j]);
		}
		fscanf(fp, "\n");
	}

	push(1, 1);

	DFS(row, col);

	for (i = 0; i < path_top; i++) {
		printf("%d %d\n", path[i].x, path[i].y);
	}

	return 0;
}