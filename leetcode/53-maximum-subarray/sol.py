class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums :
            return 0
        n = len(nums)
        max_sub = [0] * (n + 1)
        res = max_sub[0] = nums[0]

        for i in range(1, n) :
            max_sub[i] = max(nums[i], nums[i] + max_sub[i-1])
            res = max(res, max_sub[i])
        return res
