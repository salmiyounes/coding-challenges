#define MAX 0x3b9aca00

int minSubArrayLen(int target, int* nums, int numsSize) {
	int left = 0;
	int curr = 0;
	int max = MAX;
	for (int right = 0; right < numsSize; right++) {
		curr += nums[right];
		
		while (curr >= target) {
			max = max >= (right - left + 1) ? (right - left + 1) : max;
			curr -= nums[left];
			left ++;
		}
	}
	int result = max != MAX ? max : 0;
	return result;
}
