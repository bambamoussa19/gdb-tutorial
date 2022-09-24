#include "phase2.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List *List_alloc()
{
  struct List *l = calloc(1, sizeof(struct List));

  l->head = NULL;

  return l;
}

void List_free(struct List *l)
{
  struct ListNode *n, *temp;

  n = l->head;
  while (n != NULL)
  {
    temp = n->next;
    free(n);
    n = temp;
  }
}

/* Add element to end of list */
void List_push_back(struct List *l, int x)
{
  struct ListNode *temp;
  struct ListNode *n = calloc(1, sizeof(struct ListNode));
  n->val = x;
  n->next = NULL;

  if (l->head == NULL)
  {
    l->head = n;
    return;
  }

  temp = l->head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = n;
}

/* Remove/pop element from front of list */
int List_pop_front(struct List *l)
{
  int v;
  struct ListNode *head;

  if (l->head == NULL)
  {
    return 0;
  }

  head = l->head;
  v = head->val;

  l->head = head->next;

  return v;
}

void List_print(struct List *l)
{
  struct ListNode *n;
  int i = 0;

  printf("LIST START:\n");
  for (n = l->head; n != NULL; n = n->next)
  {
    printf("[%d] = %d\n", i, n->val);
    i++;
  }
  printf("LIST END\n");
}

int List_calc_avg(struct List *l)
{
  struct ListNode *n;

  int total_sum = 0;
  for (n = l->head; n != NULL; n = n->next)
  {
    total_sum += n->val;
  }

  return total_sum / l->len;
}

int main(void)
{
  int ans, temp;
  struct List *L;

  L = List_alloc();
  List_push_back(L, 15);
  List_push_back(L, 2);

  temp = List_pop_front(L);
  printf("temp: %d\n", temp);

  List_push_back(L, 13);
  ans = List_calc_avg(L);

  printf("ans: %d\n", ans);

  List_free(L);

  return 0;
}
