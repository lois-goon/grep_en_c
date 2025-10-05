#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

// implementation des méthodes

static void add(IntList *self, int value) {
  if (self->size >= self->capacity) {
    self->capacity = self->capacity * 2;
    self->data = realloc(self->data, self->capacity * sizeof(int));

    if (!self->data) {
      perror("Erreur de realloc");
      exit(EXIT_FAILURE);
    };
  };

  self->data[self->size++] = value;
};

IntList *IntList_new(size_t capacity) {
  IntList *list = malloc(sizeof(IntList))
}
