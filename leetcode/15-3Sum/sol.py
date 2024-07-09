from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        result = set()

        for index, num in enumerate(nums):
            left, right = index + 1, len(nums) - 1

            while left < right:
                current_sum = num + nums[left] + nums[right]

                if current_sum > 0:
                    right -= 1
                elif current_sum < 0:
                    left += 1
                else:
                    result.add((num, nums[left], nums[right]))
                    left += 1
                    right -= 1

        return list(result)
