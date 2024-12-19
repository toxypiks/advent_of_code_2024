#include "list.h"
#include <stdio.h>

void main(){
  // anker element
  Elem my_list = {
    .value=0,
    .next=NULL
  };

  Sublist* start = NULL;

  push(&my_list, 1);
  push(&my_list, 2);
  push(&my_list, 3);

  push_sublist(&start, my_list.next);

  Elem my_list2 = {
    .value=0,
    .next=NULL
  };
  push(&my_list2, 21);
  push(&my_list2, 22);
  push(&my_list2, 23);
  push(&my_list2, 24);

  push_sublist(&start, my_list2.next);


  Sublist* tmp = start;
  while (tmp->next_sublist){
    Elem* list_tmp = tmp->list;
    int length = list_length(list_tmp);
    for (size_t i=0;i<length;++i){
      int value = pop(&my_list);
      printf("value: %d\n", value);
    }
    printf("\n");
    tmp = tmp->next_sublist;
  }
}
