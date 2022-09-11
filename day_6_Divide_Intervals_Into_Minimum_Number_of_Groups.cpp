#include <bits/stdc++.h>
class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int minGroups(vector<vector<int>>& x) {
        int n = x.size();
        for(int i = 0; i < n; ++ i)
            x[i][1] *= -1;
        sort(x.begin(), x.end(), cmp);
        multiset<int> a;
        a.insert(x[0][1]);
        for(int i = 1; i < n; ++ i) {
            auto xx = a.upper_bound(-x[i][0]);
            if(xx == a.end())
                a.insert(x[i][1]);
            else {
                a.erase(xx);
                a.insert(x[i][1]);
            }
        }
        return a.size();
    }
};
