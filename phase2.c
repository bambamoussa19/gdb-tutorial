#include "phase2.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack *stack_new()
{
  stack *S = (stack *)calloc(1, sizeof(stack));
  Node *l = (Node *)calloc(1, sizeof(Node));
  S->top = l;
  S->floor = l;
  return S;
}

void push(stack *S, char *x, int sum)
{
  Node *l = (Node *)calloc(1, sizeof(Node));
  l->data = x;
  l->sum = sum;
  l->next = S->top;
  S->top = l;
}

/* Pop top element from the stack */
char *pop(stack *S)
{
  char *e;
  Node *temp;

  if (S->top == NULL)
  {
    return NULL;
  }

  temp = S->top;
  e = S->top->data;
  S->top = S->top->next;
  free(temp);
  return e;
}

void stack_print(stack *S)
{
  Node *l;

  printf("TOP: \n");
  for (l = S->top; l != S->floor; l = l->next)
  {
    printf("%s %d", l->data, l->sum);
    if (l->next != S->floor)
      printf(" | \n");
  }
}

int calc_avg(stack *S)
{
  Node *l;

  int total_sum = 0;
  for (l = S->top; l != S->floor; l = l->next)
  {
    total_sum += l->sum;
  }
  return total_sum / S->top->len;
}

int main()
{
  int ans;
  stack *S;

  S = stack_new();
  push(S, "a", 15);
  push(S, "b", 2);
  pop(S);
  push(S, "b", 13);
  ans = calc_avg(S);
  printf("%d", ans);

  return 0;
}
