#include <stdio.h>

#define MAX 10000
typedef struct {
        int key;
        int value;
} item;

int getValue(item* map, int comp, int size) {
        for (int i = 0; i < size; i++) {
                if (map[i].key - comp == 0) return map[i].value;
        }
        return NULL;
}

bool contains(item* map, int comp, int size) {
        for (int i = 0; i < size; i++) {
                if (map[i].key == comp) return true;
        }
        return false;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
        int* result = (int *) malloc(sizeof(int) * 2);
        item* map = (item *) malloc(sizeof(item) * MAX);

        int mapSize = 0;
        for (int i = 0; i <= numsSize; i++) {
                int comp = target - nums[i];
                if (contains(map, comp, mapSize)) {
                        result[0] = getValue(map, comp, mapSize);
                        result[1] = i;
                        *returnSize = 2;
                        free(map);
                        return result;
                }
                map[mapSize++] = (item) { .key=nums[i], .value=i };
        }
        *returnSize = 0;
        free(map);
        return NULL;
}
