#include "../include/search_algo.h"
#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGEUR_LIGNE 2048
// gestion des erreurs courantes
int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Erreur: Pas assez d'arguments. (Besoin de 3) \n");
    fprintf(stderr, "Format attendu : ./<build> <'pattern'> <filename.txt>\n");
    return 1;
  };

  char *pattern;
  char *filename;

  filename = argv[2];
  pattern = argv[1];

  FILE *haysack = fopen(filename, "r");
  if (haysack == NULL) {
    perror("Erreur fopen");
    return 1; // main return 1 quand il y a une erreur
  }

  char ligne_lue[MAX_LONGEUR_LIGNE];
  int num_ligne = 1;

  IntList *skip_table = NULL;
  bool pattern_find = false;
  bool resul = preprocess(pattern, &skip_table);

  if (!resul || skip_table == NULL) {
    fprintf(stderr, "Erreur durant le preprocessing du pattern.\n");
    fclose(haysack);
    return 1;
  };
  while (fgets(ligne_lue, MAX_LONGEUR_LIGNE, haysack) != NULL) {
    int skip = search(pattern, ligne_lue, skip_table);

    if (skip != -1) {

      printf("Numéro de la ligne : %d\n", num_ligne);
      printf("%s\n", ligne_lue);
      pattern_find = true;
    };
    num_ligne += 1;
  };
  if (!pattern_find) {
    printf("Le pattern cherché n'est pas dans le texte.\n");
  };
  // l'erreur de boucle infinie venait des char qui était codé de -127 à 127,
  // et qu'on effecutait des comparaisons en unsigned int (-1 devenait genre 1
  // milliard) mtn on a tout passé en cast unsigned char et ca fonctionne sans
  // pb
  fclose(haysack);

  free(skip_table->data);

  free(skip_table);

  return 0; // pas d'erreur donc on renvoie 0
};
