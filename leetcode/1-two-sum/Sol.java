class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                result.add(map.get(complement));
                result.add(i);
                return result.stream().mapToInt(Integer::intValue).toArray();
            } else {
                map.put(nums[i], i);
            }
        }
        
        throw new IllegalArgumentException("No two sum solution");
    }
}
