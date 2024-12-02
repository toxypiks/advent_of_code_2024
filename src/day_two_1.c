#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void read_input_matrix(int values[1000][8])
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
        num_count = 0;
        j++;
      }
      else if(buffer[0] == '\n') {
        read_row = false;
        values[i][j] = atoi(number);
      }
      else if(buffer[0] == '\0') {
        return;
      }
      else {
        if(num_count == 0) {
          number[0] = '0';
          number[1] = buffer[0];
          num_count++;
        }
        else if (num_count == 1){
          number[0] = number[1];
          number[1] = buffer[0];
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

typedef struct State{
  bool save;
  bool increasing;
  bool decreasing;
  unsigned int marker;
} State;

bool condition1(State* state, int xn, int xnp1)
{
  if ((xn - xnp1) < 0) {
    state->decreasing = true;
    if(state->increasing == true) {
      return false;
    }
  }
  if ((xn - xnp1) > 0) {
    state->increasing = true;
    if(state->decreasing == true) {
      return false;
    }
  }
  return true;
}

bool condition2(State state, int xn, int xnp1)
{
  if((abs(xn - xnp1)) > 0 && (abs(xn - xnp1)) <= 3) {
    return true;
  }
  return false;
}

bool is_end(State state, int xnp1)
{
  if((state.marker > 6) || (xnp1 == 0)) {
    return true;
  }
  return false;
}

void calc_safety(int matrix[1000][8])
{
  int num_save = {0};
  for (size_t i = 0; i < 1000; ++i) {
    State state = {
      .save = true,
      .increasing = false,
      .decreasing = false,
      .marker = 0
    };
    int xnp1 = matrix [i][state.marker+1];
    int xn = matrix[i][state.marker];        // x[n]
    while(!is_end(state, xnp1)){
      if(!condition1(&state, xn, xnp1)){
        state.save = false;
        break;
      }
      if(!condition2(state, xn, xnp1)){
        state.save = false;
        break;
      }
      state.marker += 1;
      xn = matrix[i][state.marker];        // x[n]
      xnp1 = matrix [i][state.marker+1];   // x[n+1]
    }
    if (state.save == true) {
      num_save += 1;
    }
  }
  printf("save ones : %d\n", num_save);
}

int main(void)
{
  int values[1000][8] = {0};
  read_input_matrix(values);

  calc_safety(values);
  return 0;
}
