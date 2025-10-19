#include "../include/search_algo.h"
#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// définition des fonctions
bool preprocess(char *pattern, IntList **skip_table) {
  if (*skip_table == NULL) {
    *skip_table = IntList_init(256);
  };
  int pattern_len = strlen(pattern);
  for (int i = 0; i < (*skip_table)->capacity; i++) {
    (*skip_table)->add(*skip_table, pattern_len);
  };
  for (int i = 0; i < strlen(pattern) - 1; i++) {
    (*skip_table)->data[(int)pattern[i]] = pattern_len - 1 - i;
  };
  return true;
};
