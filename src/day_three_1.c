#include <stdio.h>
#include <stdbool.h>

void read_input_window(char text_window[100])
{
  bool read_column = true;
  while(read_column) {
    bool read_row = true;
    size_t j = {0};
    int window_count = 21;

    while(read_row) {
      char buffer[2] = {0};
      fgets(buffer, 2, stdin);
      buffer[1] = 0; // 0 terminated
      if(buffer[0] == '\n') {
        read_row = false;
      }
      else if(buffer[0] == '\0') {
        return;
      }
      else {
        if(window_count > 0) {
          text_window[j] = buffer[0];
          printf("%c", text_window[j]);
          printf("\n");
          window_count--;
          j++;
        }
        if (window_count == 0){
          text_window[j] = buffer[0];
          printf("%c\n", text_window[j]);
          j++;
        }
      }
    }
  }
}

int main(void)
{
  char text[100] = {0};
  read_input_window(text);
  return 0;
}
