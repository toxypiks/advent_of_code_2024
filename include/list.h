#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#include <stdlib.h>

typedef struct Elem Elem;

struct Elem{
  int value;
  Elem* next;
};

typedef struct Sublist Sublist;

struct Sublist {
  int size;
  Elem* list;
  Sublist* next_sublist;
};

void delete(Elem* list);

int pop(Elem* list);

void push(Elem* list, int new_one);

bool is_empty(Elem* list);

size_t list_length(Elem* list);

void delete_sublist(Sublist* sublist);

Elem* pop_sublist(Sublist** sublist);

void push_sublist(Sublist** sublist, Elem* new_one);

bool is_sublist_empty(Sublist* sublist);

size_t sublist_length(Sublist* sublist);

#endif // LISTS_H_
