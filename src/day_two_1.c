#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void read_input_matrix(int values[100][8])
{
  bool read_column = true;
  size_t i = {0};
  while(read_column) {
    bool read_row = true;
    size_t j = {0};
    int num_count = {0};
    char number[2] = {0};

    while(read_row) {
      char buffer[2] = {0};
      fgets(buffer, 2, stdin);
      buffer[1] = 0; // 0 terminated
      if(buffer[0] == ' ') {
        values[i][j] = atoi(number);
        // printf("%d\n", atoi(number));
        num_count = 0;
        j++;
      }
      else if(buffer[0] == '\n') {
        read_row = false;
        values[i][j] = atoi(number);
        // printf("%d\n", atoi(number));
      }
      else if(buffer[0] == '\0') {
        return;
      }
      else {
        if(num_count < 2) {
          number[num_count] = buffer[0];
          num_count++;
        }
      }
      if (j > 8) {
        printf("Too long j\n");
        return;
      }
    }
    i++;
    if(i > 1000) {
      read_column = false;
      printf("Too long i\n");
    }
  }
}

void calc_safety(int matrix[6][5])
{
  int save = {0};
  for (size_t i = 0; i < 6; ++i) {
    int decr = {0};
    int incr = {0};
    for (size_t j = 0; j < 4; ++j) {
      if((matrix[i][j] > matrix [i][j+1]) && ((abs(matrix[i][j] - matrix[i][j+1])) <= 3)) {
        decr += 1;
      }
      else if((matrix[i][j] < matrix [i][j+1]) && ((abs(matrix[i][j+1] - matrix[i][j])) <= 3)) {
        incr += 1;
      }
    }
    if (decr == 4 || incr == 4) {
      save += 1;
    }
  }
  printf("save ones : %d\n", save);
}

int main(void)
{
  int values[1000][8] = {0};
  read_input_matrix(values);
  for(size_t i = 0; i < 1000; ++i) {
    for(size_t j = 0; j < 8; ++j) {
      printf("%d\n", values[i][j]);
    }
    printf("\n");
  }

  int test_input[][5] = {{7, 6, 4, 2, 1}, {1, 2, 7, 8, 9}, {9, 7, 6, 2, 1}, {1, 3, 2, 4, 5}, {8, 6, 4, 4, 1}, {1, 3, 6, 7, 9}};
  calc_safety(test_input);
  return 0;
}
