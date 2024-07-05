from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = {}
        
        for index, num in enumerate(nums):
            complement = target - num
            if complement in res:
                return [res[complement], index]
            
            res[num] = index

	return []
