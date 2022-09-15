#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int n = values.size();
        int mx = values[0] + values[1] - 1;
        vector<int> b = values;
        b[n - 1] -= n - 1;
        for(int i = n - 2; i > 0; -- i)
            b[i] = max(b[i + 1], b[i] - i);
        for(int i = 0; i + 1 < n; ++ i)
            mx = max(mx, values[i] + b[i + 1] + i);
        return mx;
    }
};
