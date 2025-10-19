#include "../include/search_algo.h"
#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  IntList *skip_table = NULL;
  bool resul = preprocess("Nigga", &skip_table);

  // ... après ton appel à preprocess ...

  printf("\n--- Contenu complet de la skip_table ---\n");
  printf("Taille de la table: %d\n", skip_table->size);

  for (int i = 0; i < skip_table->size; i++) {
    int skip_value;
    // On utilise ta méthode 'get' pour récupérer la valeur à l'index 'i'
    bool success = skip_table->get(skip_table, i, &skip_value);

    if (success) {
      // Vérifie si le caractère est imprimable (ASCII 32 à 126)
      if (i >= 32 && i <= 126) {
        printf("Index %3d (char '%c'): %d\n", i, (char)i, skip_value);
      } else {
        // Pour les caractères non-imprimables (comme 'null', 'tab', etc.)
        printf("Index %3d (non-pr)  : %d\n", i, skip_value);
      }
    } else {
      // Ne devrait pas arriver si ta boucle est correcte
      fprintf(stderr, "Erreur: Impossible de lire l'index %d\n", i);
    }
  }

  // ... ensuite tu peux faire tes free() ...
  free(skip_table->data);
  free(skip_table);
  free(ma_Liste->data);
  free(ma_Liste);
  return 0;
};
