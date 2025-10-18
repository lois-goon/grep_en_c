#include "../include/search_algo.h"
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

  ma_Liste->data[1] = 5;
  printf("J'ai remplace le premier élement par un %d \n", ma_Liste->data[1]);
  printf("Test de ma fonctione de preprocessing \n");

  IntList *skip_table = IntList_init(256);
  bool resul = preprocess("Hello nigga this my pattern et ca va calculer"
                          "combien pour chaque lettre de l'aphabet, on"
                          "peut skip de caractère avant de tomber dessus",
                          skip_table);
  for (int i = 0; i < skip_table->size - 1; i++) {
    printf("Nombre de char a skip pour la %d-ème lettre : %d", i,
           skip_table->data[i]);
  };
  free(skip_table->data);
  free(skip_table);
  free(ma_Liste->data);
  free(ma_Liste);
  return 0;
};
