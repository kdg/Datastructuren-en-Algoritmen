#include <stdio.h>
#include <stdlib.h>

typedef char* ELEMENT;

typedef struct node_structure {
	ELEMENT element;
	struct node_structure* next;
} NODE;

typedef struct {
	NODE* startNode;
	int size;
} STACK; 

//creatie
STACK *newStack() {
	STACK *pStack = malloc(sizeof(STACK));
	pStack->size = 0;
	pStack->startNode = NULL;
	return pStack;
}

//OPMERKING: TODO: controle op indexen!
NODE* newNode(ELEMENT element){
	NODE * pNode = malloc(sizeof(NODE));
	pNode->element = element;
	pNode->next = NULL;
	return pNode;
}

//Een nieuw element bovenaan op de stapel leggen:
void push(STACK* stack, ELEMENT element){
	//Vul aan...
}

//Het laatste element van de stapel halen
ELEMENT pop(STACK* stack){
	//Vul aan...
	return NULL;
}

//Opvragen van het laatst toegevoegde element
ELEMENT peek(STACK* stack){
	//Vul aan...
	return NULL;
}

//Printen
void printStack(STACK* stack){
	printf("Stack:\n");
	//Vul aan...
	
}

int main(int argc, char **argv) {
	STACK* myStack = newStack();
	push(myStack,"Jan");
	push(myStack,"Dirk");
	push(myStack,"Peter");
	printStack(myStack);
	pop(myStack);
	printStack(myStack);
	pop(myStack);
	printStack(myStack);
	pop(myStack);
	printStack(myStack);
	return 0;
}
