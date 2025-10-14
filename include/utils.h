#ifndef UTILS_H_ /* include guard*/
#define UTILS_H_

#include <stdlib.h>
#include <stdbool.h>


// entrainement à mimic la poo en C

typedef struct IntList IntList; 

struct IntList {
  int *data;
  int size;
  int capacity;
  
  //faire une methode pour init la liste, etc...
  void (*add)(IntList *self, int value);
  bool (*get)(IntList *self, size_t index, int *out_int);
  void (*remove)(IntList *self, size_t index);
  
  
} ;

//constructeur

IntList *IntList_init(size_t initial_capacity);


#endif // UTILS_H
