#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    	if (nums == NULL) {
		return -1;
	}
	int n = numsSize;
	int l =  0;
	int r = n - 1;
	
	while (l <= r) {
		int mid = (int) (l + r) / 2;
		if (nums[mid] == target) {
			return mid;
		} 
		if (nums[l] <= nums[mid]) {
			if (nums[l] <= target && target < nums[mid]) {
				r = --mid; 
			} else {
				l = ++mid;
			}
		} else {
			if (nums[mid] < target && target <= nums[r]) {
				l = ++mid;
			} else {
				r = --mid;
			}
		}
	}
	return -1;
}
