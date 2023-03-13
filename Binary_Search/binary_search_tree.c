#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int depth;
	int data;
	struct node* left;
	struct node* right;
}NODE;

int init = 1;
int final = 15;


NODE* tree_push(NODE* t, int init_val, int final_val, int depth);
int tree_search(NODE* t, int srch_val);
NODE* print_tree(NODE* t, int depth);

// 높이가 3인 바이너리 트리(1~15)를 자동으로 만들기
// 만든 트리에서 원하는 숫자 찾기
int main()
{
	NODE* root = NULL;

	root = tree_push(root, init, final, 0);

	printf("%d\n", tree_search(root, 6));

	print_tree(root);

	return;
}


// 함수 내에서 노드를 추가해주는 방식
NODE* tree_push(NODE* t, int init_val, int final_val, int depth)
{
	NODE* chd_node = malloc(sizeof(NODE));
	int node_data = (init_val + final_val) / 2;

	chd_node->depth = depth;

	node_init(chd_node);

	chd_node->data = node_data;

	if (init_val == node_data)
		return chd_node;

	chd_node->left = tree_push(t, init_val, node_data - 1, depth++);
	chd_node->right = tree_push(t, node_data + 1, final_val, depth++);

	return chd_node;
}

// 
int tree_search(NODE* t, int srch_val)
{
	NODE* temp = t;

	while (1)
	{
		if (temp == NULL)
		{
			printf("찾는 값이 없습니다.\n");
			return;
		}
		if (srch_val < temp->data)	temp = temp->left;
		else if (srch_val > temp->data) temp = temp->right;
		else return temp->data;
	}
}


NODE* print_tree(NODE* t, int depth)
{
	NODE* temp = t;

	for (int i = depth; i > 0; i--)
	{
		for (int j = 0; j < i; j++)	printf("\t");

		printf("\n");
	}
}

NODE* depth_search(NODE* t, int depth)
{
	NODE* temp = t;

	if (temp->depth == depth) return temp;

	if (temp->left == NULL)
	{
		if (temp->right == NULL)
			return NULL;
		else
			depth_search(temp->right, depth);
	}
	else depth_search(temp->left, depth);

}