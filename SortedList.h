#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdlib.h>
#include <assert.h>

/*
    IMPORTANT!

    As we stick to pure C, we cannot use templates. We will just asume
    some type T was previously defined.
*/

// -----------------------------------------------------------------------------

typedef struct node {
    T value;
    struct node* next;
} TNode, *TSortedList;

// TODO : Cerința 1 & Cerința 2

TSortedList create(T value) {
    // TODO (se va completa la Cerința 2)
    TSortedList list = NULL;
    list = (TSortedList)malloc(sizeof(TNode));
    list->value = value;
    list->next = NULL;
    return list;
}

int isEmpty(TSortedList list){
    if(list == NULL) 
    return 1;
    else return 0;
}

int contains(TSortedList list , T x){
    while(list != NULL){
        if(list->value == x)
        return 1;
        list = list->next;
    }
    return 0;
}

TSortedList insert(TSortedList list , T x){
    TSortedList newList = NULL , prev , current;
    
    if(isEmpty(list) == 1){
        list = create(x);
        return list;
    }
    newList = create(x);

    if(x < list->value){
        newList->next = list;
        return newList;
    }

    prev = list;
    current = list->next;
    while(current != NULL){
        if(current->value > x){
            newList->next = current;
            prev->next = newList;
            return list;
        }
        current = current->next;
        prev = prev->next;
    }
    prev->next = newList;

    return list;
}

TSortedList deleteOnce(TSortedList list , T elem){
    TSortedList prev , current;
    if(elem == list->value){
        current = list;
        list = list->next;
        free(current);
        return list;
    }

    prev = list;
    current = list->next;
    while(current != NULL){
        if(current->value == elem){
            prev->next = current->next;
            free(current);
            return list;
        }
        current = current->next;
        prev = prev->next;
    }
    prev = NULL;
    

    return list;
}

long length(TSortedList list){
    long nr = 0;
    while(list != NULL){
        nr++;
        list = list->next;
    }
    return nr;
}

T getNth(TSortedList list , T N){
    T i = 1;
    if (N > length(list)){
        return;
    }
    else{
        while(i < N){
        list = list->next;
        i++;
    }
    return list->value;
    }
}

TSortedList freeTSortedList(TSortedList list){
    T i ;
    TSortedList NewList = list , NewList2 ;
    for(i=0 ; i<length(list) ; i++){
        NewList2 = NewList;
        NewList = NewList->next;
    free(NewList2);
    }
    return NULL;
}




#endif
