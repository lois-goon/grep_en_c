#include "../include/search_algo.h"
#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// définition des fonctions
// Dans search_algo.c

#include "../include/search_algo.h"
#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool preprocess(char *pattern, IntList **skip_table) {

  if (*skip_table == NULL) {
    *skip_table = IntList_init(256);
  }

  int pattern_len = strlen(pattern);

  // Correction du bug si le pattern est vide
  if (pattern_len == 0) {
    return false;
  }

  // On remplit la table avec la valeur de saut par défaut (longueur du pattern)
  // On utilise votre .add() pour que la .size soit correcte (256)
  for (int i = 0; i < (*skip_table)->capacity; i++) {
    (*skip_table)->add(*skip_table, pattern_len);
  }

  // On calcule les sauts spécifiques pour les caractères du pattern
  for (int i = 0; i < pattern_len - 1; i++) {

    // Correction du bug du 'char' signé (nombres négatifs)
    unsigned char char_index = (unsigned char)pattern[i];

    // On met à jour la valeur directement (plus rapide que remove+add)
    (*skip_table)->data[char_index] = pattern_len - 1 - i;
  }

  return true;
}

bool same(char *str1, char *str2, int len) {
  // faudrait gérer le cas erreur ou len <= 0
  int i = len - 1;
  while (str1[i] == str2[i]) { // possible ici par arithmétique de pointeur
    if (i == 0) {
      return true;
    };
    i = i - 1;
  };
  return false;
};

int search(char *needle, char *haystack, IntList *T) {
  // on passe par référence
  // on pourrait print ici la valeur de T avec printf(*T) en
  // déréférençant le pointeur
  int skip = 0;
  int needle_len;
  needle_len = strlen(needle);
  int haystack_len = strlen(haystack);

  while (haystack_len - skip >= needle_len) {
    if (same(haystack + skip, needle, needle_len)) {
      return skip;
    };

    int out_int;
    unsigned char char_index = (unsigned char)haystack[skip + needle_len - 1];

    T->get(T, char_index, &out_int);
    skip = skip + out_int;
  };
  return -1;
};
