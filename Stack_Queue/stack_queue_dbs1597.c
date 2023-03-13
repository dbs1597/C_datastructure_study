#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
  int value;
  struct list *next;
} stack, queue;

void stack_push(int);
int stack_pop();
void print_stack();
void stack_test();
void queue_push(int);
int queue_pop();
void print_queue();
void queue_test();

stack *top = NULL;

queue *front = NULL;
queue *rear = NULL;

int main()
{
  // stack_test();
  queue_test();
};

void stack_test()
{
  stack_push(1);
  stack_push(2);
  stack_push(3);
  stack_push(4);
  stack_push(5);

  print_stack(); // 5 4 3 2 1

  stack_pop();

  print_stack(); // 4 3 2 1
  stack_pop();

  print_stack(); // 3 2 1
  stack_pop();

  print_stack(); // 2 1
  stack_pop();

  print_stack(); // 1
  stack_pop();

  print_stack(); // empty
  stack_pop();

  print_stack(); // empty
}

void queue_test()
{
  print_queue();
  queue_pop();

  queue_push(1);
  queue_push(2);
  queue_push(3);
  queue_push(4);
  queue_push(5);

  print_queue(); // 1 2 3 4 5

  queue_pop();

  print_queue(); // 2 3 4 5
  queue_pop();

  print_queue(); // 3 4 5
  queue_pop();

  print_queue(); // 4 5
  queue_pop();

  print_queue(); // 5
  queue_pop();

  print_queue(); // empty
  queue_pop();

  print_queue(); // empty
};

void stack_push(int value)
{
  printf("value: %d\n", value);
  stack *element = (stack *)malloc(sizeof(stack));
  element->value = value;
  element->next = NULL;

  if (top != NULL)
  {
    element->next = top;
  }
  top = element;

  return;
};

int stack_pop()
{
  if (top == NULL)
  {
    printf("Stack has no value!\n");

    return -1;
  }
  else
  {
    stack *temp = top;
    int temp_int = temp->value;
    top = temp->next;
    free(temp);
    return temp_int;
  }
};

void print_stack()
{
  stack *temp = (stack *)malloc(sizeof(stack));
  temp = top;

  if (temp == NULL)
  {
    printf("Stack has no value!\n");
    return;
  };
  while (1)
  {
    if (temp != NULL)
    {
      printf("%d ", temp->value);
      temp = temp->next;
    }
    else
    {
      printf("\n");
      break;
    }
  };
  return;
};

void queue_push(int value)
{
  printf("value: %d\n", value);
  queue *element = (queue *)malloc(sizeof(queue));
  element->value = value;
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

int queue_pop()
{
  if ((front == NULL) && (rear == NULL))
  {
    printf("Queue has no value!\n");
    return -1;
  }
  else
  { 
    stack *temp = front;
    int temp_int = temp->value;
    front = temp->next;
    if (front == NULL) {
      rear = NULL;
    };
    free(temp);
    return temp_int;
  }
};

void print_queue()
{
  stack *temp = (stack *)malloc(sizeof(stack));
  temp = front;

  if (temp == NULL)
  {
    printf("Queue has no value!\n");
    return;
  };
  while (1)
  {
    if (temp != NULL)
    {
      printf("%d ", temp->value);
      temp = temp->next;
    }
    else
    {
      printf("\n");
      break;
    }
  };
  return;
}
