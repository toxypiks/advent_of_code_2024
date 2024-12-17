#include "list.h"

void push(Elem* list, int new_value){
  Elem* new = (Elem*)malloc(sizeof(Elem));
  new->value = new_value;
  new->next = NULL;

  if(list->next == NULL){
    list->next = new;
    return;
  }
  // durchhangeln bis zum letzten Element
  Elem* tmp = list->next;
  while(tmp->next != NULL){
    tmp = tmp->next;
  }
  tmp->next = new;
}

int pop(Elem* list){
  if(list->next == NULL){
    return -1;
  }
  // durchhangeln bis zum letzten Element
  Elem* tmp = list->next;
  Elem* pre_tmp = list;
  while(tmp->next != NULL){
    pre_tmp = tmp;
    tmp = tmp->next;
  }
  int return_value = tmp->value;
  free(tmp);
  pre_tmp->next = NULL;

  return return_value;
}

size_t list_length(Elem* list){
  if(list->next == NULL){
    return 0;
  }

  int counter = 1;
  Elem* tmp = list->next;
  while(tmp->next != NULL){
    tmp = tmp->next;
    counter += 1;
  }
  return counter;
}
