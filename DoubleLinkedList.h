#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <stdlib.h>
/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------
/**
 *  Linked list representation -- R2 Curs2 (Slide 8)
 */
typedef struct ListNode{
	Item elem; // Stored node value
	struct ListNode* next; // link to next node
	struct ListNode* prev; // link to prev node
} ListNode;

/**
 *  Double linked list representation -- desen Curs 3 (Slide 19)
 */
typedef struct List{
	ListNode* first; // link to the first node
	ListNode* last; // link to the last node
}List;
// -----------------------------------------------------------------------------

/**
 * Create a new node
 *  [input]: Item
 *  [output]: List*
 */
ListNode *createNode(Item elem) {
	// TODO: Cerinta 1a
	
	ListNode *l;
	l = (ListNode*)malloc(sizeof(ListNode));
	
	l->elem = elem;
	l->prev = NULL;
	l->next = NULL;
	return l;
}

/**
 * Create a new (empty)  list  -- Silde-urile 13/14 Curs 2
 *  [input]: None
 *  [output]: List*
 */
List* createList(void){
	// TODO: Cerinta 1a
	List *list = (List*)malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
	return list;
}
// -----------------------------------------------------------------------------


/**
 * Determines if the list is empty
 *  [input]: List*
 *  [output]: 1 - empty/ 0 - not empty
 */
int isEmpty(List *list){
	// TODO: Cerinta 1b
	if(list->first == NULL && list->last == NULL)
	return 1;
	else 
	return 0;
}
// -----------------------------------------------------------------------------


/**
 * Determines if a list contains a specified element
 *  [input]: List*, Item
 *  [output]: int (1 - contains/ 0 - not contains)
 */
int contains(List *list, Item elem){
	// TDOO: Cerinta 1c
	ListNode *l;
	l = list->first;
	while(l != NULL){
		if(l->elem == elem)
		return 1;
		else l = l->next;
	}
}

// -----------------------------------------------------------------------------


/**
 * Compute list length
 *  [input]: List*
 *  [output]: int
 */
int length(List *list){
	// Guard against young player errors
	if(list == NULL) return 0;

	// TODO: Cerinta 1f
	ListNode *l;
	int nr = 0;
	l = list->first;
	while(l != NULL){
		nr++;
		l = l->next;
	}
	return nr;
	
}
// -----------------------------------------------------------------------------


/**
 * Insert a new element in the list at the specified position.
 * Note: Position numbering starts with the position at index zero
 *  [input]: List*, Item, int
 *  [output]: void
 */
void insertAt(List* list, Item elem, int pos){

	// Guard against young player errors
	if(list == NULL) return;

	// TODO: Cerinta 1d
	if((pos >= (length(list)+1)) || (pos < 0))
	return;

	ListNode *l = list->first, *newcell = createNode(elem);
	int i;

	if(pos == 0){       //inseram la inceput
		if(list->first == NULL){
			list->first = newcell;
			list->last = newcell;
			return;
		}
		newcell->next = l;
		l->prev = newcell;
		newcell->prev = NULL;
		list->first = newcell;
		return ;
	}

	else if(pos == length(list)){          //inseram la final
			newcell->next = NULL;
			newcell->prev = list->last;
			list->last->next = newcell;
			list->last = newcell;
			return;
	}
	else{                                    // inseram dupa l (in interior)
		for(i = 0 ; i < pos-1 ; i++)
		l = l->next;

		newcell->next = l->next;
		l->next->prev = newcell;
		l->next = newcell;
		newcell->prev = l;
		return ;
	}

}
// -----------------------------------------------------------------------------


/**
 * Delete the first element instance form a list.
 *  [input]: List*, Item
 *  [output]: void
 */
void deleteOnce(List *list, Item elem){
	// Guard against young player errors
	if(list == NULL) return;

	//TODO: Cerinta 1e
	ListNode *l = list->first, *p;

	if(contains(list,elem) == 0)
	return;

	if(list->first == NULL)
	return ;

	if(list->first == list->last){
		l = list->first;
		list->first = NULL;
		list->last = NULL;
		free(l);
		return;
	}

	while((l != NULL) && (l->elem != elem))
	l = l->next;

	if(l == list->first){ // stergem prima celula
		l->next->prev = NULL;
		list->first = l->next;
		free(l);
		return;
	}
	else if(l == list->last){ //stergem ultima celula
		p = l->prev;
		p->next = NULL;
		list->last = p;
		free(l);
		return;
	}
	else {               //stergem o celula din interiorul listei
		p = l->prev;
		l->next->prev = p;
		p->next = l->next;
		free(l);
		return ;
	}

}
// -----------------------------------------------------------------------------


/**
 * Destroy a list.
 *  [input]: List*
 *  [output]: void
 */
List* destroyList(List* list){
	// Guard against young player errors
	if(list == NULL) return NULL;

	//TODO: Cerinta 1g
	int i ,lung;
	ListNode *l1 = list->first, *l2;
	lung = length(list);
	for(i = 0 ; i < lung ; i++){
		l2 = l1;
		l1 = l1->next;
		free(l2);
	}
	list->first = NULL;
	list->last = NULL;
	free(list);
	return NULL;
}
// -----------------------------------------------------------------------------


#endif //_DOUBLE_LINKED_LIST_H_
