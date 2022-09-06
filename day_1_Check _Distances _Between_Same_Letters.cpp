class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> dp(26, -1);
        for(int i = 0, x, n = s.size(); i < n; ++ i) {
            x = s[i] - 97;
            if(dp[x] >= 0)
                dp[x] = i - dp[x] - 1;
            else
                dp[x] = i;
        }
        for(int i = 0; i < 26; ++ i) {
            if(dp[i] == -1)
                continue;
            if(dp[i] != distance[i])
                return false;
        }
        return true;
    }
};
