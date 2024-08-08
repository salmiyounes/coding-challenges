class Solution:
    def hammingWeight(self, n: int) -> int:
        return sum((n & (0b1<<i)) > 0 for i in range(0, 32))

        
