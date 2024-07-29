from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        n = len(nums)
        max_product = [0] * n
        min_product = [0] * n
        
        max_product[0] = min_product[0] = result = nums[0]
        
        for i in range(1, n):
            if nums[i] < 0:
                max_product[i], min_product[i] = min_product[i-1] * nums[i], max_product[i-1] * nums[i]
            else:
                max_product[i], min_product[i] = max_product[i-1] * nums[i], min_product[i-1] * nums[i]
            
            max_product[i] = max(nums[i], max_product[i])
            min_product[i] = min(nums[i], min_product[i])
            
            result = max(result, max_product[i])
        
        return result
