#ifndef UTILS_H_ /* include guard*/
#define UTILS_H_

#include <stdlib.h>


// entrainement à mimic la poo en C

typedef struct IntList IntList; 

struct IntList {
  int *data;
  int size;
  int capacity;
  
  //faire une methode pour init la liste, etc...
  void (*add)(IntList *self, int value);
  int (*get)(IntList *self, size_t index);
  void (*remove)(IntList *self, size_t index);
  
  
} ;

//constructeur

IntList *IntList_init(size_t initial_capacity);


#endif // UTILS_H
