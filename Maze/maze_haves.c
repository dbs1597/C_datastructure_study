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
	int chr_dir = 3; // ĳ���Ͱ� �ٶ󺸰� �ִ� ����

	locate chr;
	path route[2] = { {{0}, 0}, {{0}, 0} }; // [0]�� y��ǥ, [1]�� x��ǥ

	chr.x = 1;
	chr.y = 1;

	while (1)
	{
		if (chr.y == MAZE_SIZE - 2 && chr.x == MAZE_SIZE - 2) break;

		check = route_check(&chr, &chr_dir);
		// ���� �ڷ� �ٽ� ���ư��� ��쿣 ���ÿ��� ��θ� �ϳ��� ����
		if (check == 1)
		{
			while (1)
			{

				if (route[0].arr[route[0].top - 1] != chr.y || route[1].arr[route[1].top - 1] != chr.x) break; // ������ ��ΰ� �ƴ� �ٸ� ��η� ���� ��� �� �̻� ��θ� ������ ���� 

				step(&chr_dir, &chr);
				route_check(&chr, &chr_dir);

				if (route[0].arr[route[0].top - 2] == chr.y && route[1].arr[route[1].top - 2] == chr.x)	pop(&route); // ������ ������ ��ΰ� �̹� ������ ��ζ�� ������ �ϳ� ����
				
				
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
		dir_left_first = (*dir + 3 + i) % 4; // �ٶ󺸴� ������ ���ʺ��� Ȯ���ϱ� ���� ����

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

// ���߿� �μ� �յ� ���� �ٲٱ�
void step(int* dir, locate* l)
{
	switch (*dir)
	{
	case 0: l->x--; return;
	case 1: l->y--; return;
	case 2: l->x++; return;
	case 3: l->y++; return;
	case -1: printf("�߸��� �Է�\n"); return;
	default: printf("����\n"); return;
	}
}

// 11 X 11 ���� ����
/*check = route_check(&chr, &chr_dir);
// ���� �ڷ� �ٽ� ���ư��� ��쿣 ���ÿ��� ��θ� �ϳ��� ����
if (check == 1)
{
	while (1)
	{

		if (route[0].arr[route[0].top - 1] != chr.y || route[1].arr[route[1].top - 1] != chr.x) break; // ������ ��ΰ� �ƴ� �ٸ� ��η� ���� ��� �� �̻� ��θ� ������ ���� 

		step(&chr_dir, &chr);
		route_check(&chr, &chr_dir);

		if (route[0].arr[route[0].top - 2] == chr.y && route[1].arr[route[1].top - 2] == chr.x)	pop(&route); // ������ ������ ��ΰ� �̹� ������ ��ζ�� ������ �ϳ� ����


	}
	push(&route, &chr);
}

step(&chr_dir, &chr);
push(&route, &chr);*/