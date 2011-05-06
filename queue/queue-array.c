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

void a_offer(QUEUE_ARRAY * queue, ELEMENT * element) {

}

ELEMENT * a_poll(QUEUE_ARRAY * QUEUE) {

}

ELEMENT * a_peek(QUEUE_ARRAY * QUEUE) {

}



void queue_array() {

}
