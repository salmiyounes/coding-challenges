class Solution 
{
    public int minSubArrayLen(int target, int[] nums) {
        Integer myinf = Integer.MAX_VALUE ;

        int left = 0;
        int curr = 0 ;

        for (int right = 0; right < nums.length ; right ++) 
        {
            curr += nums[right] ;

            while (curr >= target) 
            {
                myinf = Math.min(myinf, right - left + 1) ;
                curr -= nums[left] ;
                left += 1 ;

            }
        }

        return myinf != Integer.MAX_VALUE ? myinf : 0 ;
        
    }
}
