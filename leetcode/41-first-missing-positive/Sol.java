class Solution {
    public int firstMissingPositive(int[] nums) {
        int _min = 1, _max = nums.length + 2 ;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num = 1 ; num < _max; num ++) {
            map.put(num, 0) ;
        }

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0)+1) ;
        }

        //int result ;

        for (int key : map.keySet()) {
            if (map.get(key) == 0) {
                return key ;
            }
        }
        return -1 ;
        
    }
}
