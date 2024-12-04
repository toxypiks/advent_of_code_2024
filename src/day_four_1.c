#include <stdio.h>
#include <stdbool.h>

void read_matrix(char text[140][140])
{
  size_t i = 0;
  while(i < 140) {
    bool read_row = true;
    size_t j = {0};
    while(read_row && j < 140) {
      char buffer[2] = {0};
      fgets(buffer, 2, stdin);
      buffer[1] = 0; // 0 terminated
      if(buffer[0] == '\n') {
        read_row = false;
      } else if(buffer[0] == '\0') {
        return;
      } else {
        text[i][j] = buffer[0];
        j++;
      }
    }
    i++;
  }
  return;
}

int check_for_xmas_samx(char window[4]) {
  if (window[0] == 'X' && window[1] == 'M' && window[2] == 'A' && window[3] == 'S') {
    return 1;
  }
  if (window[0] == 'S' && window[1] == 'A' && window[2] == 'M' && window[3] == 'X') {
    return 1;
  }
  return 0;
}

int main(void)
{
  int sum = 0;
  char text[140][140] = {0};
  read_matrix(text);

  // check row wise
  for(size_t i = 0; i < 140; ++i){
    for(size_t j = 0; j < 140 - 4; ++j) {
      char window[4] = {0};
      for (size_t k = 0; k < 4; ++k) {
        window[k] = text[i][j + k];
      }
      sum += check_for_xmas_samx(window);
    }
  }
  printf("sum: %d\n", sum);
  sum = 0;

  // check column wise
  for(size_t i = 0; i < 140; ++i){
    for(size_t j = 0; j < 140 - 4; ++j) {
      char window[4] = {0};
      for (size_t k = 0; k < 4; ++k) {
        window[k] = text[j][i + k];
      }
      sum += check_for_xmas_samx(window);
    }
  }
  printf("sum: %d\n", sum);
  return 0;
}
