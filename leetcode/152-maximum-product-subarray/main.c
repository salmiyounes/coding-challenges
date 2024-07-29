#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sol.h"

#define SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int main() {
    int nums1[] = {2, 3, -2, 4};
    assert(maxProduct(nums1, SIZE(nums1)) == 6);

    int nums2[] = {-2, 0, -1};
    assert(maxProduct(nums2, SIZE(nums2)) == 0);

    int nums3[] = {-2, 3, -4};
    assert(maxProduct(nums3, SIZE(nums3)) == 24);

    int nums4[] = {0, 2};
    assert(maxProduct(nums4, SIZE(nums4)) == 2);

    int nums8[] = {-1, -3, -10, 0, 60};
    assert(maxProduct(nums8, SIZE(nums8)) == 60);

    int nums9[] = {-2, -40, 0, -2, -3};
    assert(maxProduct(nums9, SIZE(nums9)) == 80);

    printf("All test cases passed!\n");
    return 0;
}
