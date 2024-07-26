class Solution {
    public int longestOnes(int[] nums, int k) {
        int left = 0, right = 0, maxones = 0, zeorcount = 0;

        while (right < nums.length) {
            if (nums[right] == 0) {
                zeorcount ++ ;
            }

            while (zeorcount > k) {
                if (nums[left] == 0) {
                    zeorcount --;
                }
                left ++;
            }
            maxones = Math.max(maxones, right - left + 1) ;
            right ++ ;
        }


        return maxones;
    }
}
