
#include <stdio.h>
#include <stdlib.h>

typedef char ELEMENT;

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
	NODE * node = newNode(element);
	node->next = stack->startNode;
	stack->startNode = node;
}

//Het laatste element van de stapel halen
ELEMENT pop(STACK* stack){
	ELEMENT element = stack -> startNode -> element;
	stack -> startNode = stack -> startNode -> next;
	return element;
}

//Opvragen van het laatst toegevoegde element
ELEMENT peek(STACK* stack){
	//Vul aan...
	if (stack -> startNode == NULL)
		return 0x00;
	return stack -> startNode -> element;
}

int main(int argc, char **argv) {
	STACK * stack = newStack();
	printf("Tik de richting in (NOZW) of M als je de Minotaurus gedood hebt:\n");
	char invoer = 0;
	fflush (stdin);
	while (invoer != 0x4D && invoer != 0x6D) // 0x4D = 'M', 0x6D = 'm'
	{
		invoer = getchar();
		if (invoer == 0x4D) //M
			break;
		if (invoer == 0x6D) //m
			break;
		switch (invoer)
		{
		case 0x4E: //N
		case 0x6E: //n
			push(stack, 'Z');
			break;
		case 0x4F: //O
		case 0x6F: //o
			push(stack, 'W');
			break;
		case 0x5A: //Z
		case 0x7A: //z
			push(stack, 'N');
			break;
		case 0x57: //W
		case 0x77: //w
			push(stack, 'O');
			break;
		default:
			printf("\nOngeldige richting: %c %d\n", invoer, invoer);
		}
	}
	printf("De Minotaurus is dood. Dit is de weg terug:\n");
	while (peek(stack) != 0x00) {
		printf("%c", pop(stack));
	}
	printf("\n");
	return EXIT_SUCCESS;
}
