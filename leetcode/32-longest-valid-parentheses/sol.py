class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack : List[str] = [-1]
        result : int = 0

        for index, char in enumerate(s):
            if char == '(':
                stack.append(index)
            elif char == ')':
                stack.pop()
                if not stack:
                    stack.append(index)
                else:
                    result = max(result, index - stack[-1])
        return result
