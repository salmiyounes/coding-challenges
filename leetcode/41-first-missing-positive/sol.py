class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        _min, _max = 1, len(nums) + 2
        seen : Dict = {num : 0 for num in range(_min, _max)} 
        for num in nums :
            seen[num] = seen.get(num, 0) + 1
        result = [key for key in seen.keys() if seen[key] == 0]
        return result[0] if result else -1
