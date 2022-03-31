#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>
#include <math.h>

/* We assume there is a defined primitive type Item. */
typedef struct {
	int prior; // Item priority
	Item data; // Item d
}ItemType;

typedef struct heap{
	long maxHeapSize; // capacity
	long size; // number of elements
	ItemType *elem; // array of elements
} PriQueue, *APriQueue;


PriQueue* makeQueue(int maxHeapSize){
	//TODO:
	APriQueue h = malloc(sizeof(PriQueue));
	h->maxHeapSize = maxHeapSize;
	h->size = 0;
	h->elem = malloc(maxHeapSize * sizeof(PriQueue));
	return h;
}

int getLeftChild(int i){
	//TODO:
	return 2 * i + 1;
}

int getRightChild(int i) {
	//TODO:
	return 2 * i + 2;
}

int getParent(int i) {
	//TODO:
	return (i - 1) / 2;
}

ItemType getMax(APriQueue h) {
	//TODO:
	return h->elem[0];
}
void siftUp(APriQueue h, int idx) {
	//TODO:
	ItemType aux;
	int i = idx;
	
		while(h->elem[i].prior > h->elem[(i-1)/2].prior  &&  i > 0){
			aux = h->elem[i];
			h->elem[i] = h->elem[(i-1)/2];
			h->elem[(i-1)/2] = aux;
			i = (i - 1) / 2;
		}
}

void insert(PriQueue *h, ItemType x) {
	//TODO:
	if(h->size == h->maxHeapSize){
		h->elem = realloc(h->elem, 2 * h->maxHeapSize * sizeof(ItemType));
		h->maxHeapSize = 2 * h->maxHeapSize;
	}

	h->elem[h->size] = x;
	int idx = h->size;
	h->size++;
	siftUp(h, idx);
}

void siftDown(APriQueue h, int idx){
	//TODO:
	ItemType aux;
	int i = idx, j;
	while((2 * i  + 1) < h->size){
		
		j = getLeftChild(i);
		if((j< h->size) && (j+1 < h->size) && (h->elem[j].prior < h->elem[j+1].prior))
			j = getRightChild(i);
		if(h->elem[i].prior > h->elem[j].prior)
			break;
		aux = h->elem[i];
		h->elem[i] = h->elem[j];
		h->elem[j] = aux;

		i = j;
	}
	
}

void removeMax(APriQueue h) {
	//TODO:
	ItemType aux;
	if(h->size == 0) return;
	aux = h->elem[0];
	h->elem[0] = h->elem[h->size - 1];
	h->elem[h->size - 1] = aux;

	h->size--;
	siftDown(h, 0);
}

void freeQueue(APriQueue h){
	// TODO:
	int i;
	free(h->elem);
	free(h);

}

#endif
