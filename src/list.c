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

int pop(Elem** list){
  if(*list == NULL){
    return -1;
  }
  if((*list)->next == NULL){
    int tmp_int = (*list)->value;
    free((*list));
    return tmp_int;
  }
  // durchhangeln bis zum letzten Element
  Elem* tmp = (*list)->next;
  Elem* pre_tmp =  (*list);
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
  if(list == NULL){
    return 0;
  }

  if(list->next == NULL){
    return 1;
  }

  int counter = 2;
  Elem* tmp = list->next;
  while(tmp->next != NULL){
    tmp = tmp->next;
    counter += 1;
  }
  return counter;
}

//sublist stuff

void push_sublist(Sublist** sublist, Elem* new_value){
  Sublist* new = (Sublist*)malloc(sizeof(Sublist));
  new->list = new_value;
  new->next_sublist = NULL;

  if((*sublist) == NULL){
    (*sublist) = new;
    return;
  }
  // durchhangeln bis zum letzten Element
  Sublist* tmp = *sublist;
  while(tmp->next_sublist != NULL){
    tmp = tmp->next_sublist;
  }
  tmp->next_sublist = new;
}

Elem* pop_sublist(Sublist** sublist){
  if((*sublist)->next_sublist == NULL){ // just one
    Elem* tmp = (*sublist)->list;
    free((*sublist));
    (*sublist) = NULL;
    return tmp;
  }
  // durchhangeln bis zum letzten Element
  Sublist* tmp = (*sublist)->next_sublist;
  Sublist* pre_tmp = *sublist;
  while(tmp->next_sublist != NULL){
    pre_tmp = tmp;
    tmp = tmp->next_sublist;
  }
  Elem* return_value = tmp->list;
  free(tmp);
  pre_tmp->next_sublist = NULL;

  return return_value;
}

size_t sublist_length(Sublist* sublist){
  if(sublist->next_sublist == NULL){
    return 0;
  }

  int counter = 1;
  Sublist* tmp = sublist->next_sublist;
  while(tmp->next_sublist != NULL){
    tmp = tmp->next_sublist;
    counter += 1;
  }
  return counter;
}
