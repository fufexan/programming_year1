/*
 * Fufezan Mihai, 2012, lab12, ex 03
 *
 * Develop a C/C++ application considering an adequate data structure that will
 * be returned by a function. In this way more values can be returned. Display
 * the results, the initial values transferred to the function (doing whatever
 * operation inside the function) using adequate messages.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int v;
  Node *next;
} Node;

Node *insert_node(Node *, int);

int main() {
  Node *x = (Node *)malloc(sizeof(Node));
  Node *init = x, *next;
  int val;

  printf("Enter integer values to be stored in a linked list. To stop, input "
         "-1.\n");

  while (true) {
    printf("%p = ", &x);
    scanf("%d", &val);
    if (val == -1) {
      x->next = nullptr;
      break;
    }
    x = insert_node(x, val);
  }

  if (init != x) {
    printf("\nThe entered values are:\n");
    x = init->next;
    next = x->next;
    while (next != nullptr) {
      printf("%p = %d\n", x, x->v);
      next = x->next;
      free(x);
      x = next;
    }
    free(init);
  } else {
    printf("\nNo values entered!\n");
  }
  free(x);
}

Node *insert_node(Node *x, int val) {
  // insert a new node with a value in a linked list

  x->next = (Node *)malloc(sizeof(Node));
  x->next->v = val;
  x->next->next = nullptr;

  return x->next;
}
