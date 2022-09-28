class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> dp(2001);
        for(int& x: arr) {
            if(x < 0)
                dp[1000 - x]++;
            else 
                dp[x]++;
        }
        for(int i = 2; i < 1001; i += 2) {
            if((dp[i] > 0 && dp[i / 2] > 0) || (dp[1000 + i] > 0 && dp[1000 + i / 2] > 0))
                return true;
        }
        return dp[0] > 1;
    }
};
