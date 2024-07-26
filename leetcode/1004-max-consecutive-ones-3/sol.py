class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        if len(nums) == 1 and nums[0] == 1:
            return 1
        elif len(nums) == 1 and nums[0] == 0 and k == 1:
            return 1  

        result = 0
        l = 0

        while l < len(nums):
            if nums[l] == 1:
                count = 0
                right = l - 1
                while l < len(nums) and nums[l] == 1:
                    count += 1
                    l += 1
                left = l
                m = k
                zerocount, z, j = 0, 0, 0
                while right >= 0 and nums[right] == 0 and m > 0:
                    zerocount += 1
                    m -= 1
                    right -= 1
                    while right >= 0 and nums[right] == 1:
                        j += 1
                        right -= 1
                while left < len(nums) and nums[left] == 0 and m > 0:
                    zerocount += 1
                    m -= 1
                    left += 1
                    while left < len(nums) and nums[left] == 1:
                        z += 1
                        left += 1
                l = left 
                result = max(result, count + z + j + zerocount)
            else:
                l += 1
        return result
