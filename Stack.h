#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>



typedef struct StackNode{
	Item elem;
	struct StackNode *next;
}StackNode;

typedef StackNode TCelSt; // Redenumirea unui nod la notatiile din curs 
typedef StackNode *ACelSt; // Redenumirea unui pointer la nod la notatiile din curs

typedef struct Stack{
	StackNode* head;  // Varful stivei
	long size; // Numarul de elemente din stiva
}Stack;

typedef Stack TStiva; // Redenumirea stivei la notatiile din curs
typedef Stack *ASt;//  // Redenumirea unui pointer la stiva la notatiile din curs

Stack* createStack(void){
	// TODO: Cerinta 1
	Stack *stiva = (Stack*)malloc(sizeof(Stack));
	stiva->head = NULL;
	stiva->size = 0;
	
	return stiva;
}

int isStackEmpty(Stack* stack){
	// TODO: Cerinta 1
	if(stack->head == NULL)
	return 1; 
	else return 0;
}

void push(Stack *stack, Item elem){
	// TODO: Cerinta 1
	StackNode *newcell = (StackNode*)malloc(sizeof(StackNode));
	newcell->elem = elem;
	
	if(stack->size == 0){
		stack->head = newcell;
		newcell->next = NULL;
		
	}
	else{
		newcell->next = stack->head;
		stack->head = newcell;
		
	} 
	stack->size++;
	
}

Item top(Stack *stack){	
	// TODO: Cerinta 1
	if(isStackEmpty(stack) == 0)
	return stack->head->elem;
	else return NULL;
} 

void pop(Stack *stack){
	// TODO: Cerinta 1
	StackNode *aux = stack->head;
	if(stack->size == 0)
	return;
	else{
		stack->head = stack->head->next;
		free(aux);
		stack->size--;
		return;
	}
}

void destroyStack(Stack *stack){
	// TODO: Cerinta 1
	StackNode *l1, *l2;
	l1 = stack->head;
	int i;
	for(i = 0 ; i < stack->size ; i++){
		l2 = l1;
		l1 = l1->next;
		free(l2);
	}
	stack->head = NULL;
	free(stack);
	return NULL;
}

#endif 
