#ifndef SEARCH_ALGO_H
#define SEARCH_ALGO_H

#include "utils.h"
#include <stdlib.h>

IntList preprocess(char *pattern, IntList *skip_table);

bool same(char *str1, char *str2, int length);

int search(char *needle,char *haystack);

#endif
