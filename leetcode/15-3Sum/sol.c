#define MAXSIZE 0xf4240

int compare(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return (int_a > int_b) - (int_a < int_b);
}

bool findDuplicate(int** nums, int numsSize, int a, int b, int c) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i][0] == a && nums[i][1] == b && nums[i][2] == c) return true;
    }
    return false;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int** result = (int**)malloc(sizeof(int*) * MAXSIZE);
    int resSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 
        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int currSum = nums[i] + nums[left] + nums[right];
            if (currSum > 0) {
                right--;
            } else if (currSum < 0) {
                left++;
            } else {
                if (!findDuplicate(result, resSize, nums[i], nums[left], nums[right])) {
                    result[resSize] = (int*)malloc(sizeof(int) * 3);
                    result[resSize][0] = nums[i];
                    result[resSize][1] = nums[left];
                    result[resSize][2] = nums[right];
                    resSize++;
                }
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * resSize);
    for (int i = 0; i < resSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    *returnSize = resSize;

    return result;
}
