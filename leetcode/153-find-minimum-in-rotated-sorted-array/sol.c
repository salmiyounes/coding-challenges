#include <stdio.h>
#include <assert.h>

int min(const int a, const int b) { 
        return a>b?b:a;
}

int findMin(int* nums, int numsSize) {
        int result = nums[0];
        int left = 0, right = numsSize - 1;

        while (left < right) {
                int mid = (int) (right + left) / 2;
                result = min(result, min(nums[mid], min(nums[left], nums[right])));
                if (nums[mid] > nums[right]) { 
                        if (nums[left] > nums[right]) { 
                                left = mid + 1;
                        } else right = mid - 1;
                } else if (nums[right] > nums[mid]) { 
                        if (nums[right] > nums[left]) left = mid + 1;
                        else right = mid - 1;
                }
                
        }
        return result;
}

int main() {
    int test1[] = {3, 4, 5, 1, 2};
    assert(findMin(test1, 5) == 1);

    int test2[] = {4, 5, 6, 7, 0, 1, 2};
    assert(findMin(test2, 7) == 0);

    int test3[] = {11, 13, 15, 17};
    assert(findMin(test3, 4) == 11);

    int test4[] = {2, 2, 2, 0, 1};
    assert(findMin(test4, 5) == 0);

    int test5[] = {1};
    assert(findMin(test5, 1) == 1);

    int test6[] = {2, 1};
    assert(findMin(test6, 2) == 1);

    int test7[] = {1, 2, 3, 4, 5, 6, 7};
    assert(findMin(test7, 7) == 1);

    printf("All tests passed.\n");
    return 0;
}
