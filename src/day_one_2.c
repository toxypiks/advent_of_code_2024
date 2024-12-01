#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void read_input(int* values_first, int* values_second, size_t size)
{
  bool read_column = true;
  size_t i = 0;
  while(read_column)
  {
    bool read_row = true;
    size_t j = 0;
    size_t k = 0;
    char number1_buf[16] = {0};
    char number2_buf[16] = {0};
    bool second_number = false;

    while(read_row)
    {
      char buffer[2] = {0};
      fgets(buffer, 2, stdin);
      buffer[1] = 0; // 0 terminated
      if(buffer[0] == '\n')
      {
        values_first[i] = atoi(number1_buf);
        values_second[i] = atoi(number2_buf);
        read_row = false;
      }
      else if(buffer[0] == '\0')
      {
        return;
      }
      else if(buffer[0] == ' ')
      {
        second_number = true;
      }
      else
      {
        if((j < 16) && (second_number == false)) {
          number1_buf[j] = buffer[0];
        }
        else if((second_number == true) && (k<16)) {
          number2_buf[k] = buffer[0];
          k++;
        }
      }
      j++;
      if(j >= 16){
        printf("too long\n");
        return;
      }
    }
    i++;
    if(i > size)
    {
      read_column = false;
    }
  }
}

void bubble_sort(int* values, size_t size)
{
  for (size_t i=0; i < size; i++){
    bool has_switch = false;
    size_t end = size - i;

    for (size_t j = 0; j < end-1; j++) {
      if (values[j] > values[j+1]) {
        int temp = values[j];
        values[j] = values[j+1];
        values[j+1] = temp;
        has_switch = true;
      }
    }
    if(!has_switch) return;
  }
}

int sum_occurency(int* value_first, int* values_second, size_t size)
{
  int result = {0};
  for(size_t i = 0; i < size; ++i) {
    int count = {0};
    int number = value_first[i];
    for(size_t j = 0; j < size; ++j) {
      if (values_second[j] == number) {
        count += 1;
      }
    }
    result += number * count;
  }
  return result;
}


int main (void)
{
  int values_first[1000] = {0};
  int values_second[1000] = {0};
  read_input(values_first, values_second, 1000);

  bubble_sort(values_first, 1000);
  bubble_sort(values_second, 1000);

  int sum_occ = sum_occurency(values_first, values_second, 1000);
  printf("total sum occurency %d\n", sum_occ);
  return 0;
}
