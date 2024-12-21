#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

typedef struct Rule{
  int value1;
  int value2;
} Rule;

size_t read_row(char text[6])
{
  bool read_text = true;
  size_t j = {0};
  while(j < 6) {
    char buffer[2] = {0};
    fgets(buffer, 2, stdin);
    buffer[1] = 0; // 0 terminated
    if(buffer[0] == '\n') {
      text[j] = 0;
      return j;
    }
    else {
      text[j] = buffer[0];
      j++;
    }
  }
  // null terminierend
  text[j] = 0;
  return j;
}

int read_number(char text[3])
{
  bool read_text = true;
  size_t j = {0};
  while(j < 3) {
    char buffer[2] = {0};
    fgets(buffer, 2, stdin);
    buffer[1] = 0; // null terminated
    if(buffer[0] == ',') {
      text[j] = 0;
      return -1;
    }
    else if(buffer[0] == '\n') {
      text[j] = 0;
      return -2;
    }
    else if(buffer[0] == '\0') {
      text[j] = 0;
      return -3;
    }
    else {
      text[j] = buffer[0];
      j++;
    }
  }
  // null terminated
  text[j] = 0;
  return -4;
}


size_t read_input(Rule rule_list[8], Elem* number_list){
  bool read = true;

  size_t i = 0;
  while(read == true){
    char text[6] = {0};
    size_t row_length = read_row(text);
    // if row_length = 0 end of input
    if(row_length == 5){
      text[2] = 0;
      int number_1 = atoi(&text[0]);
      int number_2 = atoi(&text[3]);
      rule_list[i].value1 = number_1;
      rule_list[i].value2 = number_2;
      i++;
      // TODO not needed later
      if(i >=8){
        break;
      }
    } else {
      break;
    }
  }
  // 2nd part
  char text[3] = {0};
  int stop = read_number(text); // jump over empty line

  while(true){
    char text[3] = {0};

    int stop = read_number(text);
    if(stop == -1){
      int value = atoi(text);
      push(number_list, value);
      continue;
    }
    if(stop == -2){
      int value = atoi(text);
      push(number_list, value);
      break;
    }
  }
  return i;
}



int main (void)
{
  printf("Hello\n");
  Rule rule_list[8];
  Elem number_list = {
    .value=0,
    .next=NULL
  };

  size_t length = read_input(rule_list, &number_list);

  /* for(size_t i = 0; i < length; ++i) {
    printf("%d %d\n", rule_list[i].value1, rule_list[i].value2);
    }*/

  size_t number_list_length = list_length(&number_list);

  for (size_t i = 0; i < number_list_length ;++i){
    // int value = pop(&number_list);
    // printf("value: %d\n", value);
  }
  return 0;
}
