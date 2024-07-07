class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1) {
            return s.length() ;
        }

        int max_length = 0, start = 0, end = 0;
        HashMap<Character, Integer> map = new HashMap<>() ;

        for (char c : s.toCharArray()) {
            if (map.containsKey(c) && map.get(c) >= start) {
                start = map.get(c) + 1 ;
            }
            map.put(c, end);
            int curr_length = end - start + 1 ;

            max_length = Math.max(max_length, curr_length);
            end ++ ;
        }



        return max_length ;

        
    }
}
