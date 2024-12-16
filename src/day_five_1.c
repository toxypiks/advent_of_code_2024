#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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


size_t read_input(Rule rule_list[8]){
  bool read = true;

  size_t i = 0;
  while(read == true){
    char text[6] = {0};
    size_t row_length = read_row(text);
    printf("row_length: %d text: %s\n",row_length,text);
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
  return i;
}



int main (void)
{
  printf("Hello\n");
  Rule rule_list[8];
  size_t length = read_input(rule_list);

  for(size_t i = 0; i < length; ++i) {
    printf("%d %d\n", rule_list[i].value1, rule_list[i].value2);
  }

  return 0;
}
