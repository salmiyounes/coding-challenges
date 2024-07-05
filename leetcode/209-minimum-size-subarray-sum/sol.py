from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        result = float("inf")
        left = 0
        current_sum = 0

        for right in range(len(nums)) :
            current_sum += nums[right]

            while current_sum >=  target :
                result = min(result, right - left +1)
                current_sum -= nums[left]
                left += 1
        return result if result != float("inf") else 0

