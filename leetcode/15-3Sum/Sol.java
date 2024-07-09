import java.util.*;

class Solution {
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> result = new HashSet<>();

        for (int i = 0; i < nums.length - 2; i++) {
            int l = i + 1;
            int r = nums.length - 1;
            while (l < r) {
                int curr = nums[i] + nums[l] + nums[r];
                if (curr > 0) {
                    r--;
                } else if (curr < 0) {
                    l++;
                } else {
                    List<Integer> triplet = Arrays.asList(nums[i], nums[l], nums[r]);
                    result.add(triplet);
                    l++;
                    r--;
                }
            } 
        }
        return new ArrayList<>(result);
    }
}
