#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "crc32.h"


#define BUCKETS_SIZE 100
//#define DO_SIZE

typedef char* ELEMENT;

typedef struct {
	ELEMENT key;
	ELEMENT value;
} BUCKET;

typedef struct {
	BUCKET* buckets;
#ifdef DO_SIZE
	int size; // mag je weglaten!
#endif
} HASHMAP;

HASHMAP* newMap() {
	// hier uitwerken!
	HASHMAP * h = malloc(sizeof(HASHMAP));
	h -> buckets = calloc(BUCKETS_SIZE, sizeof(BUCKET));
#ifdef DO_SIZE
	h -> size = 0;
#endif
}

int hash(char* string){
	// hier uitwerken (zie opdracht slide 15)
	chksum_crc32gentab();
	return abs(chksum_crc32(string, strlen(string)) % BUCKETS_SIZE);
}

void put(HASHMAP* map,ELEMENT key, ELEMENT value){
	int h = hash(key);
	//map -> buckets[h] = malloc(sizeof(BUCKET));
	map -> buckets[h] . key = key;
	map -> buckets[h] . value = value;
}

ELEMENT get(HASHMAP* map,ELEMENT key){
	// hier uitwerken!
	return map -> buckets[hash(key)] . value;
}

void removePair(HASHMAP* map, ELEMENT key){
	map -> buckets[hash(key)] . value = NULL;
	map -> buckets[hash(key)] . key = NULL;
	// hier uitwerken!
}

void printMap(HASHMAP* map){
	int i;
	printf("Map:\n");
	for (i=0;i<BUCKETS_SIZE;i++) {
		//printf("%d:\n",i);
		if (map->buckets[i].key!=NULL){
			printf("%s:%s\n",map->buckets[i].key,map->buckets[i].value);
		}
	}
}

void freeMemory(HASHMAP* map) {
	free(map->buckets);
	free(map);
}

int main(int argc, char **argv) {
	printf("HashMap_met_Collision.\nHashtest:\n");
	char *strFrank = "frank";
	char *strJef = "jef";
	char *strDirk = "dirk";
	char *strLeen = "leen";
	char *strNele = "nele";
	printf("hash(%s)=%d\n",strFrank,hash(strFrank));
	printf("hash(%s)=%d\n",strJef,hash(strJef));
	printf("hash(%s)=%d\n",strDirk,hash(strDirk));
	printf("hash(%s)=%d\n",strLeen,hash(strLeen));
	printf("hash(%s)=%d\n",strNele,hash(strNele));
	HASHMAP* map = newMap();
	put(map, strFrank, "0486/11.33.23");
	put(map, strJef, "0486/10.20.30");
	put(map, strDirk, "0475/11.39.12");
	put(map, strLeen, "0473/45.89.56");
	put(map, strNele, "0485/83.39.90");
	printMap(map);
	printf("Nummer van leen: %s\n",get(map, strLeen));
	printf("Nummer van nele: %s\n",get(map, strNele));
	//printf("Nummer van ?: %s\n",get(map, "bla")); // --> null
	printf("Jef verwijderen...\n");
	removePair(map, strJef);
	removePair(map, "bla");	
	printMap(map);
	freeMemory(map);
	return 0;
}


