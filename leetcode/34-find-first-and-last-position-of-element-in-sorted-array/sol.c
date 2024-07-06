#include <stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int left = 0;
	int right = numsSize  - 1;
	int* result = (int *) malloc(sizeof(int) * 2);
	result[0] = -1;
	result[1] = -1; 
 	while (left <= right) {
		int mid = (int) (left + right) / 2;
		if (nums[mid] == target) {
			result[0] = mid;
			result[1] = mid;
			int i = mid - 1;	
			int j = mid + 1;
			while (i >= 0 && nums[i] == target) {
				result[0] = i;
				i --;
			}
			while (j < numsSize && nums[j] == target) {
				result[1] = j;
				j ++;
			}
			return result;
		} else if (nums[mid] > target) {
			right = mid - 1;
		} else if (nums[mid] < target) {
			left  = mid + 1;
		}
	}
	*(returnSize) = 0;
	return result;
}
