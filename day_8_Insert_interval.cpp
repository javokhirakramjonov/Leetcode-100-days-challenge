class Solution {
public:
    int getPosition(vector<vector<int>>& a, int target) {
        int l = 0, r = a.size() - 1, m;
        while(l < r) {
            m = l + ((r - l) >> 1);
            if(a[m][0] <= target && target <= a[m][1])
                return m;
            if(target < a[m][0])
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        if(a.empty()) {
            a.push_back(b);
            return a;
        }
        if(b[1] < a[0][0]) {
            a.insert(a.begin(), b);
            return a;
        }
        if(a[a.size() - 1][1] < b[0]) {
            a.push_back(b);
            return a;
        }
        int l = getPosition(a, b[0]);
        int r = getPosition(a, b[1]);
        if(b[1] < a[l][0] && l == r) {
            a.insert(a.begin() + l, b);
            return a;
        }
        if(l == r) {
            a[l][0] = min(a[l][0], b[0]);
            a[l][1] = max(a[l][1], b[1]);
            return a;
        }
        a[l][0] = min(a[l][0], b[0]);
        if(a[r][0] > b[1])
            --r;
        a[r][1] = max(a[r][1], b[1]);
        if(l < r) {
            a[l][1] = a[r][1];
            a.erase(a.begin() + l + 1, a.begin() + r + 1);
        }
        return a;
    }
};
