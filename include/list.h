#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#include <stdlib.h>

typedef struct Elem Elem;

struct Elem{
  int value;
  Elem* next;
};

void delete(Elem* list);

int pop(Elem* list);

void push(Elem* list, int new_one);

bool is_empty(Elem* list);

size_t list_length(Elem* list);

#endif // LISTS_H_
