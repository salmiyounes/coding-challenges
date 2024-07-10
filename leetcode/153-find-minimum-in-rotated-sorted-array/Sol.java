class Solution {
    public int findMin(int[] nums) {
        int res = nums[0];
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int mid = (int) (right + left) / 2;
            res = Math.min(res, Math.min(nums[mid], Math.min(nums[left], nums[right])));
            if (nums[mid] > nums[right]) {
                if (nums[left] > nums[right]) {
                    left = mid + 1;
                } else right = mid - 1;

            }
            else if (nums[right] > nums[mid]) {
                if (nums[right] > nums[left]) {
                    left = mid + 1;
                } else right = mid - 1;
            }
        }

        return res;
    }
}
