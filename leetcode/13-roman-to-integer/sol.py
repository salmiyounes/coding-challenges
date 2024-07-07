class Solution:
    def romanToInt(self, s: str) -> int:
        if not s:
            return 0
        
        hash_map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        prev_value = 0
        total = 0
        
        for char in reversed(s):
            current_value = hash_map[char]
            
            if current_value < prev_value:
                total -= current_value
            else:
                total += current_value
                
            prev_value = current_value
        
        return total
