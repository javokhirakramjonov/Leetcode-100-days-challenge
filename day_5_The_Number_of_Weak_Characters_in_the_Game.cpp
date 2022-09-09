class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), cmp);
        int mx = a[n - 1][1];
        int sum = 0;
        for(int i = n - 1; i >= 0; -- i) {
            if(a[i][1] < mx)
                sum++;
            mx = max(mx, a[i][1]);
        }
        return sum;
    }
};
