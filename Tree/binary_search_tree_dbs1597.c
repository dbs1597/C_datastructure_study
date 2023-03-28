#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

typedef struct list
{
    Node* tree_node;
    struct list* next;
} queue;

Node* root = NULL;

queue* front = NULL;
queue* rear = NULL;

void tree_insert(int value);
void tree_delete(int value);

void level_order();
void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);

void queue_push(Node*);
Node* queue_pop();

//바이너리 트리, 순회

void main() {

    tree_insert(22);
    printf("%d\n", 22);
    tree_insert(15);
    printf("%d\n", 15);
    tree_insert(7);
    printf("%d\n", 7);
    tree_insert(18);
    printf("%d\n", 18);
    tree_insert(5);
    printf("%d\n", 5);
    tree_insert(10);
    printf("%d\n", 10);
    tree_insert(16);
    printf("%d\n", 16);
    tree_insert(20);
    printf("%d\n", 20);
    tree_insert(19);
    printf("%d\n", 19);
    tree_insert(45);
    printf("%d\n", 45);
    tree_insert(36);
    printf("%d\n", 36);
    tree_insert(60);
    printf("%d\n", 60);


    level_order();

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");
};

void tree_insert(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
        return;
    };

    Node* pos = root;
    while (1) {
        if (value < pos->value) {
            if (pos->left == NULL) {
                pos->left = new_node;
                return;
            }
            else {
                pos = pos->left;
                continue;
            }
        }
        else if (value > pos->value) {
            if (pos->right == NULL) {
                pos->right = new_node;
                return;
            }
            else {
                pos = pos->right;
                continue;
            }
        }
    }
};

void tree_delete(int value) {

}

void level_order() {
    if (root == NULL) {
        printf("Tree is NULL!\n");
        return;
    };

    queue_push(root);
    Node* pos = NULL;

    while (1) {
        pos = queue_pop();
        if (pos == NULL) {
            break;
        }
        printf("%d ", pos->value);
        if (pos->left != NULL) {
            queue_push(pos->left);
        }
        if (pos->right != NULL) {
            queue_push(pos->right);
        }
    }

    printf("\n");
}

void preorder(Node* node) {
    if (node == NULL) {
        printf("Tree is NULL!\n");
        return;
    };

    printf("%d ", node->value);
    if (!(node->left == NULL)) {
        preorder(node->left);
    }
    if (!(node->right == NULL)) {
        preorder(node->right);
    }
}

void inorder(Node* node) {
    if (node == NULL) {
        printf("Tree is NULL!\n");
        return;
    };

    if (!(node->left == NULL)) {
        inorder(node->left);
    }
    printf("%d ", node->value);
    if (!(node->right == NULL)) {
        inorder(node->right);
    }
}

void postorder(Node* node) {
    if (node == NULL) {
        printf("Tree is NULL!\n");
        return;
    };

    if (!(node->left == NULL)) {
        postorder(node->left);
    }
    if (!(node->right == NULL)) {
        postorder(node->right);
    }
    printf("%d ", node->value);
}

void queue_push(Node* tree_node)
{
    // printf("value: %d\n", tree_node->value);
    queue* element = (queue*)malloc(sizeof(queue));
    element->tree_node = tree_node;
    element->next = NULL;

    if ((front == NULL) && (rear == NULL))
    {
        front = element;
    }
    else
    {
        rear->next = element;
    };
    rear = element;

    return;
};

Node* queue_pop()
{
    if ((front == NULL) && (rear == NULL))
    {
        // printf("Queue has no value!\n");
        return NULL;
    }
    else
    {
        queue* temp = front;
        Node* temp_node = temp->tree_node;
        front = temp->next;
        if (front == NULL) {
            rear = NULL;
        };
        free(temp);
        return temp_node;
    }
};