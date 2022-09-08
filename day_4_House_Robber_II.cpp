class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int temp = nums[0];
        nums[0] = 0;
        int x = get(nums);
        nums[0] = temp;
        nums[n - 1] = 0;
        int y = get(nums);
        return max(x, y);
    }
    
    int get(vector<int> nums) {
        int n = nums.size();
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = nums[1];
        if(n > 2) {
            dp[2] = nums[2] + dp[0];
        }
        for(int i = 3; i < n; ++ i) {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        }
        for(int i = 1; i < n; ++ i)
            dp[0] = max(dp[0], dp[i]);
        return dp[0];
    }
};
