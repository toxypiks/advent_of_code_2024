#include <stdio.h>
#include <stdbool.h>

void read_matrix(char text[140][140])
{
  size_t i = 0;
  while(i < 140) {
    bool read_row = true;
    size_t j = {0};
    while(read_row && j < 141) {
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

int check_for_mas_sam(char window[3][3]) {
  if (((window[0][0] == 'M' && window [2][2] == 'S') ||
       (window[0][0] == 'S' && window [2][2] == 'M')) &&
      ((window[0][2] == 'M' && window [2][0] == 'S') ||
       (window[0][2] == 'S' && window [2][0] == 'M')) &&
      window[1][1] == 'A') {
    return 1;
  }
  return 0;
}

int main (void)
{
  int sum = 0;
  char text[140][140] = {0};
  read_matrix(text);

  for(size_t col = 0; col < 140 - 2; ++col){
    for(size_t row = 0; row < 140 - 2; ++row){
      // window stuff
      char window[3][3] = {0};
      for(size_t window_col = 0; window_col < 3; ++window_col){
        for(size_t window_row = 0; window_row < 3; ++window_row){
          window[window_col][window_row] = text[col + window_col][row + window_row];
        }
      }
      sum += check_for_mas_sam(window);
    }
  }
  printf("sum of mas and sam: %d\n", sum);
}
