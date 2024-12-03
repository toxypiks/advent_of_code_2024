#include <stdio.h>
#include <stdbool.h>
#include <regex.h>
#include <stdlib.h>

size_t read_input_window(char text[20000])
{
  bool read_text = true;
  size_t j = {0};
  while(read_text && j < 20000) {
    bool read_row = true;

    char buffer[2] = {0};
    fgets(buffer, 2, stdin);
    buffer[1] = 0; // 0 terminated
    if(buffer[0] == '\0') {
      return j;
    }
    else {
      text[j] = buffer[0];
      j++;
    }
  }
  return j;
}

int string_to_int(char window[13], size_t no1_start, size_t no1_end, size_t no2_start, size_t no2_end)
{
  char no1[4] = {0};
  size_t j = 0;
  for(size_t i = no1_start; i < no1_end; ++i) {
    no1[j] = window[i];
    j++;
  }
  char no2[4] = {0};
  j = 0;
  for(size_t i = no2_start; i < no2_end; ++i) {
    no2[j] = window[i];
    j++;
  }
  int result =  atoi(no1) * atoi(no2);
  printf("result: %d %s %s \n",result, no1,no2);
  return result;
}

int check_window(char window[13]){
  window[12] = 0;
  if (window[0] == 'm' && window[1] == 'u' && window[2] == 'l' && window[3] == '('){
    //regexshizzle
    int result = 0;
    regex_t reg;
    regex_t reg_no1;
    regex_t reg_no2;
    char* pattern = "^mul\\([0-9]+,[0-9]+\\)";
    char* pattern_no1 = "\\([0-9]+,";
    char* pattern_no2 = ",[0-9]+\\)";
    if (regcomp(&reg, pattern , REG_EXTENDED | REG_NOSUB) != 0) return -1;
    result = regexec(&reg, window, 0, 0, 0);
    if (result == 0){
      if (regcomp(&reg_no1, pattern_no1 , REG_EXTENDED | REG_NOSUB) != 0) return -1;
      if (regcomp(&reg_no2, pattern_no2 , REG_EXTENDED | REG_NOSUB) != 0) return -1;
      regmatch_t pm_no1;
      if (regexec(&reg_no1, window, 1, &pm_no1, REG_NOTBOL) != 0) return -1;
      regmatch_t pm_no2;
      if (regexec(&reg_no2, window, 1, &pm_no2, REG_NOTBOL) != 0) return -1;
      size_t no1_start = pm_no1.rm_so+1;
      size_t no1_end   = pm_no1.rm_eo-1;
      size_t no2_start = pm_no2.rm_so+1;
      size_t no2_end   = pm_no2.rm_eo-1;
      printf("no1/no2 %d %d %d %d\n",no1_start, no1_end, no2_start, no2_end);
      return string_to_int(window, no1_start, no1_end, no2_start, no2_end);
      regfree(&reg_no1);
      regfree(&reg_no2);
    }
    regfree(&reg);
    return 0;
  }
  return 0;
}

int main(void)
{
  char text[20000] = {0};

  int num_mul = 0;
  size_t text_size = read_input_window(text);
  for (size_t i = 0; i < text_size - 13 + 1; ++i) {
    char window[13] = {0};
    for (size_t j = 0; j < 13; ++j) {
      window[j] = text[i + j];
    }
    num_mul += check_window(window);
  }
  printf("num_mul: %d\n", num_mul);
  return 0;
}
