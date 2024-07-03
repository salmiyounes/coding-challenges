class Solution {
    public String expand(String s, Integer l, Integer r) {
        while ((l >= 0) && (r < s.length()) && (s.charAt(l) == s.charAt(r))) {
            l --;
            r ++;
        } 

        String result = s.substring(l+1, r) ;

        return result;
    }
    public String longestPalindrome(String s) {

        String _max = "";

        for (int i = 0 ; i < s.length(); i++) {
            String odd = expand(s, i, i) ;

            _max = (odd.length() > _max.length()) ? odd : _max ;

            String even = expand(s, i, i+1) ;

            _max = (even.length() > _max.length()) ? even : _max ; 
        }

        return _max ;
        
    }
}
