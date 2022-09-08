class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int mx = max(nums[0], n > 1 ? nums[1] : 0);
        for(int i = 2; i < n; ++ i) {
            if(i > 2)
                nums[i] += max(nums[i - 2], nums[i - 3]);
            else
                nums[i] += nums[i - 2];
            mx = max(mx, nums[i]);
        }
        return mx;
    }
};
