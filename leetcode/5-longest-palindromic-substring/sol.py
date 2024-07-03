
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(l: int, r: int) -> str:
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l + 1:r]

        longest_palindrome = ''
        for i in range(len(s)):
            palindrome_odd = expand(i, i)
            if len(palindrome_odd) > len(longest_palindrome):
                longest_palindrome = palindrome_odd

            palindrome_even = expand(i, i + 1)
            if len(palindrome_even) > len(longest_palindrome):
                longest_palindrome = palindrome_even

        return longest_palindrome
