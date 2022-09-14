class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0], mx = temp;
        for(int i = 1; i < n; ++ i) {
            temp = max(temp + nums[i], nums[i]);
            mx = max(mx, temp);
        }
        vector<int> a = nums, b = a;
        for(int i = 1; i < n; ++ i)
            a[i] += a[i - 1];
        for(int i = n - 2; i >= 0; -- i)
            b[i] += b[i + 1];
        for(int i = 1; i < n; ++ i)
            a[i] = max(a[i], a[i - 1]);
        for(int i = n - 2; i >= 0; -- i)
            b[i] = max(b[i], b[i + 1]);
        for(int i = 1; i < n - 1; ++ i)
            mx = max(mx, a[i] + b[i + 1]);
        return mx;
    }
};
