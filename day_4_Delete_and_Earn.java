class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] mp = new int[20_001];
        int[] dp = new int[20_001];
        for(int x: nums)
            mp[x] += x;
        dp[1] = mp[1];
        dp[2] = mp[2];
        int mx = max(dp[1], dp[2]);
        for(int i = 3; i < 20_001; ++ i) {
            dp[i] = mp[i] + max(dp[i - 2], dp[i - 3]);
            mx = max(mx, dp[i]);
        }
        return mx;
    }
    
    private int max(int a, int b) {
        return a > b ? a : b;
    }
}
