#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("hello nigga \n");

  IntList *ma_Liste = IntList_init(4);
  ma_Liste->add(ma_Liste, 10);

  ma_Liste->add(ma_Liste, 5);
  ma_Liste->add(ma_Liste, 3);
  ma_Liste->add(ma_Liste, 4);

  for (int i = 0; i < ma_Liste->size; i++) {
    int out_int;
    ma_Liste->get(ma_Liste, i, &out_int);

    printf("Ma IntList contient %d a l'index %d \n", out_int, i);
    printf("Voici ma size %d \n", ma_Liste->capacity);
  };

  ma_Liste->remove(ma_Liste, 2);
  printf("\nj'ai maintenant supprimé le deuxième élement de ma liste \n");
  for (int i = 0; i < ma_Liste->size; i++) {
    int out_int;
    ma_Liste->get(ma_Liste, i, &out_int);

    printf("Ma IntList contient %d a l'index %d \n", out_int, i);
    printf("Voici ma size %d \n", ma_Liste->size);
  };

  free(ma_Liste->data);
  free(ma_Liste);
  return 0;
}
