#include "../include/search_algo.h"
#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// définition des fonctions
bool preprocess(char *pattern, IntList *skip_table) {
  skip_table = IntList_init(256);
  for (int i = 0; i < skip_table->size; i++) {
    skip_table->add(skip_table, strlen(pattern));
  };
  for (int i = 0; i < strlen(pattern) - 1; i++) {
    skip_table->data[pattern[i]] = strlen(pattern) - 1 - i;
  };
  return true;
};
