class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)

        max_length = 0
        start = 0  
        char_index_map = {}  

        for end, char in enumerate(s):
            if char in char_index_map and char_index_map[char] >= start:
                start = char_index_map[char] + 1  

            char_index_map[char] = end  
            current_length = end - start + 1  

            max_length = max(max_length, current_length)

        return max_length
