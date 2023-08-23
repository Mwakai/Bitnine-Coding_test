#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int type;
  int value;
  struct Node *left;
  struct Node *right;
} Node;

enum TypeTag
{
  ADD,
  SUB,
  MUL,
  DIV,
  ABS,
  FIB,
};

Node *makeFunc(int type, int value, Node *left, Node *right)
{
  Node *node = malloc(sizeof(Node));
  node->type = type;
  node->value = value;
  node->left = left;
  node->right = right;
  return node;
}

int calc(Node *node)
{
  if (node == NULL) {
    return 0;
  }
  
  switch (node->type)
  {
  case ADD:
    return calc(node->left) + calc(node->right);
  case SUB:
    return calc(node->left) - calc(node->right);
  case MUL:
    return calc(node->left) * calc(node->right);
  case DIV:
    return calc(node->left) / calc(node->right);
  case ABS:
    return abs(calc(node->left));
  case FIB:
    return fibonacci(node->value);
  default:
    return 0;
  }
}

int fibonacci(int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main()
{
  Node *add = makeFunc(ADD, 0, makeFunc(FIB, 6, NULL, NULL), makeFunc(FIB, 4, NULL, NULL));
  Node *mul = makeFunc(MUL, 0, makeFunc(FIB, 3, NULL, NULL), makeFunc(FIB, 2, NULL, NULL));
  Node *sub = makeFunc(SUB, 0, add, mul);
  Node *fibo = makeFunc(FIB, 2, NULL, NULL);

  printf("add: %d\n", calc(add));
  printf("mul: %d\n", calc(mul));
  printf("sub: %d\n", calc(sub));
  printf("fibo: %d\n", calc(fibo));

  return 0;
}

