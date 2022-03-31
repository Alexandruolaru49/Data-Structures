#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
	Item elem;
	struct QueueNode *next;
}QueueNode;

typedef QueueNode TcelQ;
typedef QueueNode *ACelQ;

typedef struct Queue{
	QueueNode *front;
	QueueNode *rear;
	long size;
}Queue;

typedef Queue TCoada;
typedef Queue *AQ;


Queue* createQueue(void){
	// TODO: Cerinta 2
	Queue *coada = (Queue*)malloc(sizeof(Queue));
	coada->front = NULL;
	coada->rear = NULL;
	coada->size = 0;
	return coada;
} 

int isQueueEmpty(Queue *q){
	// TODO: Cerinta 2
	if(q->front == NULL)
	return 1;
	else return 0;
}

void enqueue(Queue *q, Item elem){
	// TODO: Cerinta 2
	QueueNode *newcell = (QueueNode*)malloc(sizeof(QueueNode));
	newcell->elem = elem;
	if(q->front == NULL){
		newcell->next = NULL;
		q->front = newcell;
		q->rear = newcell;
		q->size++;
	}
	else{
		newcell->next = NULL;
		q->rear->next = newcell;
		q->rear = newcell;
		q->size++;
	}	
}

Item front(Queue* q){
	// TODO: Cerinta 2
	if(q->front != NULL)
	return q->front->elem;
	else return NULL;
}

void dequeue(Queue* q){
	// TODO: Cerinta 2
	QueueNode *aux = q->front;
	if(q->front == NULL)
	return ;
	else{
		q->front = q->front->next;
		if(q->size == 1){
			q->rear = NULL;
		}
		free(aux);
		q->size--;
	}
}

void destroyQueue(Queue *q){
	// TODO: Cerinta 2
	QueueNode *l1 ,*l2;
	int i;
	l1 = q->front;
	for(i = 0 ;i < q->size ; i++){
		l2 = l1;
		l1 = l1->next;
		free(l2);
	}
	q->front = NULL;
	q->rear = NULL;
	free(q);
	return NULL;
}

#endif
