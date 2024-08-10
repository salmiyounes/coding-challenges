class Solution:
    def calc(self, n: int, count: int, l: List[int]) -> int:
        if (n <= 1) :
            if len(l) == 0:
                l.append(count)
            else:
                l.append(min(l[-1], count)) 
            return 
        if (n & 1) :
            for num in [n - 1, n + 1]:
                self.calc(num, count+1, l)
        else :
            self.calc(n >> 1, count+1, l)
        return l[-1]

    def integerReplacement(self, n: int) -> int:
        if n == 1: return 0
        return self.calc(n, 0, [])
        
