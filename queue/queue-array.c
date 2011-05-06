/*
 * queue-array.c
 *
 *  Created on: May 6, 2011
 *      Author: Yvan JANSSENS
 */

#include "functions.h"



typedef struct queue_array {
	ELEMENT * elementen;
	int capaciteit;
	int grootte;
} QUEUE_ARRAY;

void a_queue_expand(QUEUE_ARRAY * queue) {
	queue -> capaciteit *= 2;
	ELEMENT * nieuweElementen = malloc(sizeof(ELEMENT) * queue -> capaciteit);
	int i = 0;
	for (i = 0; i < queue -> grootte; i++)
		nieuweElementen[i] = queue -> elementen[i];
	free(queue -> elementen);
	queue -> elementen = nieuweElementen;
}

QUEUE_ARRAY * a_new_queue() {
	QUEUE_ARRAY *pRet = malloc(sizeof(QUEUE_ARRAY));
	pRet -> capaciteit = INITIELE_CAPACITEIT;
	pRet -> elementen = malloc (sizeof(ELEMENT) * pRet ->capaciteit);
	pRet -> grootte = 0;
	return pRet;
}

void a_add_element(QUEUE_ARRAY* queue, ELEMENT element, int index){
	if (queue-> grootte == queue -> capaciteit) {
		a_queue_expand(queue);
	}
	int i;
	for (i=queue->grootte;i>index;i--) {
		queue -> elementen[i] = queue -> elementen[i - 1];
	}
	queue -> elementen[index] = element;
	queue -> grootte++;

}

void a_remove_element(QUEUE_ARRAY* queue, int index){
	int i;
	for (i=index;i< queue -> grootte;i++) {
		queue -> elementen[i] = queue -> elementen[i + 1];
	}
	queue -> grootte--;
}

ELEMENT a_get_element(QUEUE_ARRAY * queue, int index){
	return queue -> elementen[index];
}

void a_offer(QUEUE_ARRAY * queue, ELEMENT element) {
	a_add_element(queue, element, queue -> grootte);
}

ELEMENT a_poll(QUEUE_ARRAY * queue) {
	ELEMENT element = queue -> elementen[0];
	// Elementen allemaal shiften omlaag shiften...
	int teller = 0;
	for (teller = 0; teller < (queue -> grootte); teller ++) {
		queue -> elementen[teller] = queue -> elementen[teller + 1];
	}
	queue -> grootte -= 1;
	return element;
}

ELEMENT a_peek(QUEUE_ARRAY * queue) {
	return a_get_element(queue, 0);
}

void a_print_queue(QUEUE_ARRAY * queue) {
	int teller = 0;
	for (teller = 0; teller < queue -> grootte; teller ++)
		printf("%d: %s \n", teller, queue -> elementen[teller]);
}



void queue_array() {
	QUEUE_ARRAY * myQueue = a_new_queue();
	a_offer(myQueue,"Jan");
	a_offer(myQueue,"Dirk");
	a_offer(myQueue,"Peter");
	a_print_queue(myQueue);
	ELEMENT element = a_poll(myQueue);
	printf("Polling %s\n", element);
	a_print_queue(myQueue);
	element = a_poll(myQueue);
	printf("Polling %s\n", element);
	a_print_queue(myQueue);
	element = a_poll(myQueue);
	printf("Polling %s\n", element);
	a_print_queue(myQueue);
}
