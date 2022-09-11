class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> a(100001);
        int mx = -1;
        for(int i: nums) {
            if(i & 1)
                continue;
            a[i]++;
            if(mx == -1)
                mx = i;
            else if(a[i] > a[mx])
                mx = i;
            else if(a[i] == a[mx])
                mx = min(mx, i);
        }
        return mx;
    }
};
