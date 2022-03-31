#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <stdio.h>                                          // needed for printf
#include <stdlib.h>                           // needed for alloc, realloc, free

/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------

/*
  OrderedSet represents a set with elements of type T stored in memory
  in an ordered fashion.
*/

typedef struct OrderedSet {
  T* elements;                    // pointer to where the elements are in memory
  long size;                                // the number of elements in the set
  long capacity;                      // the current capacity (allocated memory)
} OrderedSet;

// -----------------------------------------------------------------------------

/*
  Function that creates an OrderedSet with elements of type T with a given
  initial capacity.
*/

OrderedSet* createOrderedSet(long initialCapacity) {

  OrderedSet* newSet = (OrderedSet*) malloc(sizeof(OrderedSet));

  newSet->size = 0;                        // initially, the set is empty
  newSet->capacity = initialCapacity;
  newSet->elements = (T*) malloc(initialCapacity * sizeof(T));

  return newSet;
}

// -----------------------------------------------------------------------------

/*
  Function that checks if an element exists in a given set. As the
  elements of the set are ordered in memory, this function uses binary
  search.

  Function returns 1 if the given element exists in the set, and 0
  otherwise.
*/

int contains(OrderedSet* set, const T element) {
  // TODO : Cerința 2

  long start , mij , end , OK=0;
  start = 0;
  end = set->size-1;

  while((start <= end) && (OK==0))
  {
    mij = (start + end)/2; 
    if(element == set->elements[mij])
    {
      OK = 1;
    }
    if(element > set->elements[mij])
    {
      start = mij + 1;
    }
    if(element < set->elements[mij])
    {
      end = mij - 1;
    }

  }
  if(OK == 0)
  return 0;
  else return 1;
}

// -----------------------------------------------------------------------------

/*
  Function that adds a new element to a set. If the element was
  already in the set, nothing changes. Otherwise, the element is added
  to the set. In the end, the elements must be in ascending order.
*/

void add(OrderedSet* set, const T newElement) {
  // TODO : Cerința 2
  if(set->size == 0)
  {
    set->elements[0] = newElement; 
    set->size ++;
  }
  
  long i = (set->size)-1 , OK = 0;
  if(contains(set,newElement) == 0)
  {
    while((i >= 0) && (OK ==0))
    {
      if(newElement < (set->elements[i]))
      {
        set->elements[i+1] = set->elements[i];
      }
      else if(newElement > (set->elements[i]))
           {
             
             
             set->elements[i+1] = newElement;
             set->size++;
             return ;
           }
      i--;
    }
    if(i == -1)
    {
      set->elements[0] = newElement;
      set->size ++ ;
    }
  }
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the union of
  the two
*/

OrderedSet* unionOrderedSets(OrderedSet* s1, OrderedSet* s2) {
  // TODO : Cerința 3

  
  OrderedSet *s3 = createOrderedSet(s1->size + s2->size);
  long i=0 , j=0 , k=0;

  for(i=0 ; i<s1->size ; i++)
  {
    add(s3,s1->elements[i]);
  }

  for(j=0 ; j<s2->size ; j++)
  {
    if(contains(s3,s2->elements[j]) == 0)
    {
      add(s3,s2->elements[j]);
      
    }
  }

  return s3;
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the
  intersection of the two
*/

OrderedSet* intersectOrderedSets(OrderedSet* s1, OrderedSet* s2) {
  // TODO : Cerința 3
  long max;
  if((s1->size) > (s2->size))
  max = s1->size;
  else max = s2->size;
  OrderedSet *s3 = createOrderedSet(max);
  long i ;
  for(i=0 ; i<s1->size ; i++)
  {
    if(contains(s2,s1->elements[i]) == 1)
    {
      add(s3,s1->elements[i]);
    }
  }
  return s3;
}


// -----------------------------------------------------------------------------

#endif
