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

int check_for_xmas_samx(char window[4]) {
  if (window[0] == 'X' && window[1] == 'M' && window[2] == 'A' && window[3] == 'S') {
    return 1;
  }
  if (window[0] == 'S' && window[1] == 'A' && window[2] == 'M' && window[3] == 'X') {
    return 1;
  }
  return 0;
}

size_t get_row_length(size_t j, size_t col_length){
  if(j < col_length/2){
    return j+1;
  } else{
    return col_length - j;
  }
}

char matrix_diagonal_right_at(size_t i,size_t j, char matrix[140][140], size_t length){
  size_t x = 0;
  size_t y = 0;
  if( i < length/2){
    x = i - j;
    y = j;
  } else {
    x = length/2 - j;
    y = (i - length/2) + j;
  }
  return matrix[y][x];
}

char matrix_diagonal_left_at(size_t i,size_t j, char matrix[140][140], size_t length){
  size_t x = 0;
  size_t y = 0;
  if( i < length/2){
    x = j;
    y = (length/2 - i) + j;
  } else {
    x = (i - length/2) + j;
    y = j;
  }
  return matrix[y][x];
}

int main(void)
{
  int sum = 0;
  char text[140][140] = {0};
  read_matrix(text);

  // check row wise
  for(size_t i = 0; i < 140; ++i){
    for(size_t j = 0; j < 140 - 3; ++j) {
      char window[4] = {0};
      for (size_t k = 0; k < 4; ++k) {
        window[k] = text[i][j + k];
      }
      sum += check_for_xmas_samx(window);
    }
  }
  printf("sum row: %d\n", sum);

  // check column wise
  for(size_t i = 0; i < 140; ++i){
    for(size_t j = 0; j < 140 - 3; ++j) {
      char window[4] = {0};
      for (size_t k = 0; k < 4; ++k) {
        window[k] = text[j + k][i];
      }
      sum += check_for_xmas_samx(window);
    }
  }

  printf("sum row + col: %d\n", sum);

  int length = 2*140-1;
  // check diagonal right
  for(size_t i = 0; i < length; ++i){
    size_t row_size = get_row_length(i,length);
    if(row_size >=4 ){
      for(size_t j = 0; j < row_size - 3; ++j) {
        char window[4] = {0};
        for (size_t k = 0; k < 4; ++k) {
          window[k] = matrix_diagonal_right_at(i,j + k, text, length);
        }
        sum += check_for_xmas_samx(window);
      }
    }
  }

  printf("sum row + col + diag right: %d\n", sum);

  // check diagonal left
  for(size_t i = 0; i < length; ++i){
    size_t row_size =  get_row_length(i,length);
    if(row_size >=4 ){
      for(size_t j = 0; j < row_size - 3; ++j) {
        char window[4] = {0};
        for (size_t k = 0; k < 4; ++k) {
          window[k] = matrix_diagonal_left_at(i,j + k, text, length);
        }
        sum += check_for_xmas_samx(window);
      }
    }
  }

  printf("sum: %d\n", sum);
  return 0;
}
