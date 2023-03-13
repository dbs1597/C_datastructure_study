#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 17
#define SIZE 100

typedef struct
{
	int arr[SIZE];
	int top;
}path;

typedef struct
{
	int x;
	int y;
}locate;


void push(path* s, locate* l);
void pop(path* s);
int route_check(locate *s, int* dir);
void step(int* dir, locate *s);


int maze[MAZE_SIZE][MAZE_SIZE] ={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0},
{0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0},
{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
{0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0},
{0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0},
{0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0},
{0,1,0,0,1,0,1,1,1,0,0,1,0,0,0,1,0},
{0,1,1,1,1,0,0,0,1,0,1,0,1,1,1,1,0},
{0,1,0,0,1,0,0,0,1,0,1,1,1,0,0,1,0},
{0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,1,0},
{0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0},
{0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
{0,1,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0},
{0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

// 11 X 11
//{{0,0,0,0,0,0,0,0,0,0,0,0,0},
//{0,1,1,1,1,0,0,0,0,1,0,0,0},
//{0,1,0,1,1,1,0,0,0,1,0,0,0},
//{0,1,0,1,0,1,1,1,1,1,0,0,0},
//{0,1,1,1,0,1,0,0,0,1,1,1,0},
//{0,0,1,0,0,1,0,0,0,0,0,1,0},
//{0,0,1,0,0,1,0,1,1,1,0,0,0},
//{0,0,1,1,0,0,0,1,0,1,0,0,0},
//{0,0,0,1,0,0,0,1,0,1,1,0,0},
//{0,0,0,1,1,1,1,1,0,0,1,1,0},
//{0,1,1,1,0,0,0,1,0,1,0,1,0},
//{0,0,0,1,0,0,0,1,1,1,0,1,0},
//{0,0,0,0,0,0,0,0,0,0,0,0,0} };

// 7 x 7
//{{0,0,0,0,0,0,0,0,0},
//{ 0,1,1,1,1,1,0,0,0 },
//{ 0,1,0,0,0,1,0,0,0 },
//{ 0,1,0,0,0,1,0,0,0 },
//{ 0,1,0,0,0,1,0,0,0 },
//{ 0,1,0,1,1,1,0,0,0 },
//{ 0,1,0,1,0,1,0,0,0 },
//{ 0,1,1,1,0,1,1,1,0 },
//{ 0,0,0,0,0,0,0,0,0 }}



int main()
{
	int check;
	int chr_dir = 3; // 캐릭터가 바라보고 있는 방향

	locate chr;
	path route[2] = { {{0}, 0}, {{0}, 0} }; // [0]이 y좌표, [1]이 x좌표

	chr.x = 1;
	chr.y = 1;

	while (1)
	{
		if (chr.y == MAZE_SIZE - 2 && chr.x == MAZE_SIZE - 2) break;

		check = route_check(&chr, &chr_dir);
		// 만약 뒤로 다시 돌아가는 경우엔 스택에서 경로를 하나씩 지움
		if (check == 1)
		{
			while (1)
			{

				if (route[0].arr[route[0].top - 1] != chr.y || route[1].arr[route[1].top - 1] != chr.x) break; // 지났던 경로가 아닌 다른 경로로 가는 경우 더 이상 경로를 지우지 않음 

				step(&chr_dir, &chr);
				route_check(&chr, &chr_dir);

				if (route[0].arr[route[0].top - 2] == chr.y && route[1].arr[route[1].top - 2] == chr.x)	pop(&route); // 앞으로 진행할 경로가 이미 지났던 경로라면 스택을 하나 지움
				
				
			}
			push(&route, &chr);
		}

		step(&chr_dir, &chr);
		push(&route, &chr);

		printf("%d, %d\n", chr.x, chr.y);
	}
	printf("===========================");
	for (int i = 0; i < route[0].top; i++)
		printf("%d, %d\n", route[1].arr[i], route[0].arr[i]);


	return 0;
}

void push(path* s, locate* l)
{
	s[0].arr[(s[0].top)++] = l->y;
	s[1].arr[(s[1].top)++] = l->x;
	return;
}

void pop(path* s)
{
	s[0].arr[--(s[0].top)];
	s[1].arr[--(s[1].top)];
	return;
}

int route_check(locate* l, int* dir)
{
	int dir_left_first;
	for (int i = 0; i < 4; i++)
	{
		dir_left_first = (*dir + 3 + i) % 4; // 바라보는 방향의 왼쪽부터 확인하기 위해 설정

		switch (dir_left_first)
		{
		case 0: if (maze[l->y][l->x - 1] == 1) break; continue;
		case 1: if (maze[l->y - 1][l->x] == 1) break; continue;
		case 2: if (maze[l->y][l->x + 1] == 1) break; continue;
		case 3: if (maze[l->y + 1][l->x] == 1) break; continue;
		}

		if ((dir_left_first + 2) % 4 == *dir)
		{
			*dir = dir_left_first;
			return 1;
		}
		*dir = dir_left_first;
		return 0;
	}
	return -1;
}

// 나중에 인수 앞뒤 순서 바꾸기
void step(int* dir, locate* l)
{
	switch (*dir)
	{
	case 0: l->x--; return;
	case 1: l->y--; return;
	case 2: l->x++; return;
	case 3: l->y++; return;
	case -1: printf("잘못된 입력\n"); return;
	default: printf("오류\n"); return;
	}
}

// 11 X 11 에선 가능
/*check = route_check(&chr, &chr_dir);
// 만약 뒤로 다시 돌아가는 경우엔 스택에서 경로를 하나씩 지움
if (check == 1)
{
	while (1)
	{

		if (route[0].arr[route[0].top - 1] != chr.y || route[1].arr[route[1].top - 1] != chr.x) break; // 지났던 경로가 아닌 다른 경로로 가는 경우 더 이상 경로를 지우지 않음 

		step(&chr_dir, &chr);
		route_check(&chr, &chr_dir);

		if (route[0].arr[route[0].top - 2] == chr.y && route[1].arr[route[1].top - 2] == chr.x)	pop(&route); // 앞으로 진행할 경로가 이미 지났던 경로라면 스택을 하나 지움


	}
	push(&route, &chr);
}

step(&chr_dir, &chr);
push(&route, &chr);*/