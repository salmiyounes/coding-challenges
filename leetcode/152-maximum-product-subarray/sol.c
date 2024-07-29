#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(const int a, const int b) {
    return a > b ? a:b;
}

int min(const int a, const int b) {
    return a > b ? b:a;
}

int maxProduct(int* nums, int numsSize) {
    if (!nums) return 0;
    if (numsSize == 1) return nums[0];

    size_t *maxNums = (size_t *) malloc(sizeof(size_t) * numsSize);
    memset(maxNums, 0, sizeof(size_t) * numsSize);
    size_t *minNums = (size_t *) malloc(sizeof(size_t) * numsSize);
    memset(minNums, 0, sizeof(size_t) * numsSize);
    size_t result ;
    maxNums[0] = minNums[0] = result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < 0) {
            maxNums[i] = minNums[i-1] * nums[i] ;
            minNums[i] = maxNums[i-1] * nums[i] ;

        } else {
            maxNums[i] = (maxNums[i-1] * nums[i]) ;
            minNums[i] = (minNums[i-1] * nums[i]) ;
        }

        maxNums[i] = max(nums[i], maxNums[i]);
        minNums[i] = min(nums[i], minNums[i]);

        result = max(result, maxNums[i]);
    }

    return (int)result;
    
}
