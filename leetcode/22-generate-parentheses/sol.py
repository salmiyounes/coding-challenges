class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        memo = []
        return self.fct(memo, '', n, 0, 0)
    def fct(self, memo: List[str], string: str, n: int, right: int, left: int) -> List[str]:
        if n * 2 == len(string):
            memo.append(string)
            return
        if left < n :
            self.fct(memo, string + '(', n, right, left+1)
        if right < left :
            self.fct(memo, string + ')', n, right+1, left)
        return memo 
        
