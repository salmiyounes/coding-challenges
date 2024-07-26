
int max(const int a, const int b) {return a > b ? a: b;}

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, right = 0, maxones = 0, zero = 0;

    while (right < numsSize) {
        if (*(nums + right) == 0) {
            zero++;
        }

        while (zero > k) {
            if (*(nums + left) == 0) zero--;
            left ++;
        }

        maxones = max(maxones, right - left + 1);
        right ++;
    }

    return maxones;
}
