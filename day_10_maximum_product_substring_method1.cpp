class Solution {
public:
    int getMax(vector<int> &a) {
        int n = a.size();
        int mx = a[0];
        int zeroes = 0;
        int l, r;
        l = r = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                ++zeroes;
                if (l < 0)
                    l = i;
                r = i;
            }
        }
        for (int i = 1; i < n; ++i)
            a[i] *= a[i - 1];
        if (!(zeroes & 1))
            return a[n - 1];
        int left = l != 0 ? a[l - 1] : a[0];
        int right = l != n - 1 ? a[n - 1] / a[l] : a[n - 1];
        mx = max(mx, max(left, right));
        l = r;
        left = l != 0 ? a[l - 1] : a[0];
        right = l != n - 1 ? a[n - 1] / a[l] : a[n - 1];
        mx = max(mx, max(left, right));
        return mx;
    }

    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector <vector<int>> a;
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if(!temp.empty())
                    a.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(nums[i]);
        }
        if (!temp.empty())
            a.push_back(temp);
        if(a.empty())
            return 0;
        int mx = a[0].size() != nums.size() ? 0 : nums[0];
        for (vector<int> x: a) {
            mx = max(mx, getMax(x));
        }
        return mx;
    }
};
