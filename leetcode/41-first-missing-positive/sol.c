#include <stdio.h>
#include <stdlib.h>

#define MAPSIZE 0x186a0

typedef struct {
	int key;
	int value;
} item;

int getvalue(item* map, int mapSize, int key) {
	for (int i = 0; i < mapSize; i++) if (map[i].key == key) return i;
	return -1;
}

int firstMissingPositive(int* nums, int numsSize) {
	int min = 1, max = numsSize + 2;
	item* map = (item *) malloc(sizeof(item) * MAPSIZE);
	int mapSize = 0;
	
	for (int num = 1; num < max; num++) {
		map[mapSize++] = (item) {.key=num, .value=0};
	}
	ssize_t index;
	for (int i = 0; i < numsSize; i++) {
		if (index = getvalue(map, mapSize, nums[i]) != -1) {
			map[index].value ++;
		}
	}
	
	for (int i = 0; i < mapSize; i++) {
		if (map[i].key == 0) {
			int result = ma[i].key;
			free(map);
			return result;
		}
	}
	
	free(map);
	return -1;
}
