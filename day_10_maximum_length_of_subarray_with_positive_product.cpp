#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMax(vector<int> &a) {
        int n = a.size();
        int mx = 0;
        int negatives = 0;
        int l, r;
        l = r = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                ++negatives;
                if (l < 0)
                    l = i;
                r = i;
            } else
                mx = 1;
        }
        if (!(negatives & 1))
            return a.size();
        return max({mx, r, (int)a.size() - l - 1});
    }

    int getMaxLen(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> a;
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (!temp.empty())
                    a.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(nums[i]);
        }
        if (!temp.empty())
            a.push_back(temp);
        if (a.empty())
            return 0;
        int mx = 0;
        for (vector<int> x: a) {
            mx = max(mx, getMax(x));
        }
        return mx;
    }
};
