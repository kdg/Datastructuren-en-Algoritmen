/*
 * queue-ll.c
 *
 *  Created on: May 6, 2011
 *      Author: Yvan JANSSENS
 */
#include "functions.h"

typedef struct node_structure {
	ELEMENT element;
	struct node_structure* next;
} NODE;

typedef struct {
	NODE* startNode;
	int grootte;
} QUEUE_LINKEDLIST;

NODE* l_new_node(ELEMENT element){
	NODE * pNode = malloc(sizeof(NODE));
	pNode->element = element;
	pNode->next = NULL;
	return pNode;
}

QUEUE_LINKEDLIST *l_new_queue() {
	QUEUE_LINKEDLIST *p = malloc(sizeof(QUEUE_LINKEDLIST));
	p -> grootte = 0;
	p -> startNode = NULL;
	return p;
}

void l_offer(QUEUE_LINKEDLIST * queue, ELEMENT element) {
	NODE * node = queue -> startNode;
	if (node != NULL) {
		while (1) {
			if (node -> next == NULL)
				break;
			node = node -> next;
		};
		node -> next = l_new_node(element);
	} else {
		queue -> startNode = l_new_node(element);
	}

}

ELEMENT l_peek(QUEUE_LINKEDLIST * queue) {
	return queue -> startNode -> element;
}

void l_print_queue(QUEUE_LINKEDLIST * queue) {
	NODE * node = queue -> startNode;
	int teller = 0;
	while (node != NULL)
	{
		printf("%d: %s \n", teller ++, node -> element);
		node = node -> next;
	}
}

ELEMENT l_poll(QUEUE_LINKEDLIST * queue) {
	ELEMENT el = queue -> startNode -> element;
	queue -> startNode = queue -> startNode -> next;
	return el;
}

void queue_linkedlist() {
	QUEUE_LINKEDLIST * myQueue = l_new_queue();
	l_offer(myQueue,"Jan");
	l_offer(myQueue,"Dirk");
	l_offer(myQueue,"Peter");
	l_print_queue(myQueue);
	ELEMENT element = l_poll(myQueue);
	printf("Polling %s\n", element);
	l_print_queue(myQueue);
	element = l_poll(myQueue);
	printf("Polling %s\n", element);
	l_print_queue(myQueue);
	element = l_poll(myQueue);
	printf("Polling %s\n", element);
	l_print_queue(myQueue);
}
