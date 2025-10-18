#include "../include/utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// implementation de ma IntList dynamique pour mon super egrep

static void add(IntList *self, int value) {

  // gestion erreurs
  if (self->size >= self->capacity) {
    self->capacity = self->capacity * 2;
    self->data = realloc(self->data, self->capacity * sizeof(int));

    if (!self->data) {
      perror("Erreur de realloc");
      exit(EXIT_FAILURE);
    };
  };
  // fonction

  self->data[self->size++] = value;
};

static void remove_int(IntList *self, size_t index) {
  if (self->size == 0) {
    fprintf(stderr, "[IntList::remove] Erreur : tentative de suppression d'un "
                    "element d'une IntList vide");
    return;
  };
  if (self == NULL) {

    fprintf(stderr, "[IntList::remove] Erreur : Pointeur NULL reçu");
    return;
  };

  // fontion qui reconstruit la liste sans l'élément
  for (int i = index; i < self->size - 1; i++) {
    self->data[i] = self->data[i + 1];
  };

  self->size--;
};

static bool get_int(IntList *self, size_t index, int *out_int) {
  if (self->size == 0) {
    fprintf(stderr, "[Intlist::get] Erreur : Tentative de recuperation d'un "
                    "element d'une liste vide");

    return false;
  };
  *out_int = self->data[index];

  // fonction
  return true;
};

// constructeur de IntList

IntList *IntList_init(size_t init_capacity) {
  // assignation attributs et mémoire

  IntList *list = malloc(sizeof(IntList));
  list->data = malloc(init_capacity * sizeof(int));
  list->capacity = init_capacity;
  list->size = 0;

  // assignation des méthodes
  list->add = add;
  list->remove = remove_int;
  list->get = get_int;
  return list;
};
