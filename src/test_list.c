#include "list.h"
#include <stdio.h>

void main(){
  Elem my_list = {
    .value=0,
    .next=NULL
  };

  push(&my_list, 1);
  push(&my_list, 2);
  push(&my_list, 3);

  int length = list_length(&my_list);

  for (size_t i=0;i<length;++i){
    int value = pop(&my_list);
    printf("value: %d\n", value);
  }
}
