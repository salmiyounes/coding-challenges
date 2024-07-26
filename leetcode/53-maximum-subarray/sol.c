
int max(const int a, const int b) {return a>b?a:b;}

int maxSubArray(int* nums, int n) {
    if (nums == NULL) return 0;

    int *maxSub = (int *) malloc(sizeof(int) * (n+1));
    memset(maxSub, 0, sizeof(int) * (n+1));
    int result = maxSub[0] = nums[0];

    for (int i = 1; i < n; i++) {
        maxSub[i] = max(nums[i], nums[i] + maxSub[i-1]);
        result = max(result, maxSub[i]);
    }

    free(maxSub);
    return result;
}
