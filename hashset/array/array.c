#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef char* ELEMENT; 

typedef struct {
	ELEMENT* keys;
	ELEMENT* values;
	int size;
} MAP;

MAP* newMap() {
 // hier uitwerken
}

void put(MAP* map,ELEMENT key, ELEMENT value){
 // hier uitwerken	
}

ELEMENT get(MAP* map,ELEMENT key){
  // hier uitwerken  	
}

int getKeyIndex(MAP* map, ELEMENT key) {
	int i;
	for (i= 0;i<map->size;i++) {
		if (map->keys[i] == key) {
			return i;	
		}
	}
	return -1;
}

void removePair(MAP* map, ELEMENT key){
   // hier uitwerken	
}

void printMap(MAP* map){
	int i;
	printf("Map:\n");
	for (i=0;i<map->size;i++) {
		printf("%s:%s\n",map->keys[i],map->values[i]);
	}
}

void freeMemory(MAP* map) {
	free(map->keys);
	free(map->values);
	free(map);
}

int main(int argc, char **argv) {
	MAP* map = newMap();
	char *strFrank = "frank";
	char *strJef = "jef";
	char *strDirk = "dirk";
	put(map, strFrank, "0486/11.33.23");
	put(map, strJef, "0486/10.20.30");
	put(map, strDirk, "0475/11.39.12");
	printMap(map);
	printf("Nummer van frank: %s\n",get(map, strFrank));
	printf("Jef verwijderen...\n");
	removePair(map, strJef);
	removePair(map, "bla");
	printMap(map);
	freeMemory(map);
	return 0;
}
