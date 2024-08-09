class Solution:
    def reverseBits(self, n: int) -> int:
        res: int = 0
        for i in range(32):
            res |= ((n & (1 << i)) > 0) << (31 - i)
        return res
