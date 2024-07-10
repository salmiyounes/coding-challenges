class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        n: int = len(nums) - 1
        left, right = 0, n
        res: int = float('inf')

        while left < right :
            mid = (left+right) // 2
            res = min(res, nums[mid], nums[left], nums[right])
            if nums[mid] > nums[right]:
                if nums[left] > nums[right] :
                    left = mid + 1
                else:
                    right = mid - 1
            elif nums[right] > nums[mid] :
                if nums[right] > nums[left]:
                    left = mid + 1
                else:
                    right = mid - 1
        return res
