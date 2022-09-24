#ifndef __PHASE2_H__
#define __PHASE2_H__

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct List
{
  int len;
  struct ListNode *head;
};

struct List *List_alloc();
void List_free(struct List *l);

void List_push_back(struct List *l, int x);
int List_pop_front(struct List *l);

void List_print(struct List *l);
int List_calc_avg(struct List *l);

#endif