class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int mx = nums[0];
        int mn = nums[0];
        int res = nums[0];
        int temp;
        for(int i = 1; i < n; ++ i) {
            if(nums[i] < 0) {
                temp = mx;
                mx = mn;
                mn = temp;
            }
            mx = Math.max(nums[i], mx * nums[i]);
            mn = Math.min(nums[i], mn * nums[i]);
            res = Math.max(mx, res);
        }
        return res;
    }
}

