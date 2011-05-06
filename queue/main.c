/*
 * main.c
 *
 *  Created on: May 6, 2011
 *      Author: Yvan JANSSENS (janssensyvan@telenet.be)
 */
#include "functions.h"

int main(int argc, char **argv) {
	printf("array: \n");
	queue_array();
	printf("linkedlist: \n");
	queue_linkedlist();
	return EXIT_SUCCESS;
}
