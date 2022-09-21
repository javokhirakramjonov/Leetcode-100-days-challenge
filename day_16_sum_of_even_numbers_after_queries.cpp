class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans(n);
        int s = 0;
        for(int& x: nums)
            s += (x & 1) ? 0 : x;
        int m = queries.size();
        int a, b, i = 0;
        for(vector<int>&x: queries) {
            a = x[0];
            b = x[1];
            if(nums[b] & 1) {
                nums[b] += a;
                if(a & 1)
                    s += nums[b];
            } else {
                nums[b] += a;
                if(a & 1) {
                    s -= nums[b] - a;
                } else {
                    s += a;
                }
            }
            ans[i++] = s;
        }
        return ans;
    }
};
