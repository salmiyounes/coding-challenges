class Solution {
    public int romanToInt(String s) {
        if (s == null) 
        {
        	return 0 ;
        } 
        HashMap<Character,  Integer> map = new HashMap<>();
        map.put('I', 1) ;
        map.put('V', 5);	
        map.put('X', 10) ;
        map.put('L', 50) ;
        map.put('C', 100) ;
        map.put('D', 500) ;
        map.put('M', 1000) ;
        String string = new StringBuilder(s).reverse().toString();
        
        int prev_value = 0 ;
        int total = 0 ;

        for (char c : string.toCharArray()) 
        {
        	int curr = map.get(c) ;

        	if (curr < prev_value) 
        	{
        		total -= curr ;
        	} else 
        	{
        		total += curr ;
        	}

        	prev_value = curr ;
        }

        return total ;
        
    }
}
