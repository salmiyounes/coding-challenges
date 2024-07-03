#include <stdio.h>

int jump(int* nums, int numsSize) {
    	int count = 0;
	int goal = numsSize - 1;
	
	while (goal > 0) {
		int diff = -1;
		int j = goal - 1;
		while (j >= 0) {
			if (goal - j <= nums[j]) {
				diff = diff >= (goal - j) ? diff : (goal - j);
			}
			j --;
		}
		goal -= diff;
		count ++;
	}
	return count;
}
