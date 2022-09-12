class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.empty())
            return 0;
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1, sum = 0, mx = 0;
        while(true) {
            while(l <= r && power >= tokens[l]) {
                mx = max(mx, ++sum);
                power -= tokens[l ++];
            }
            if(r >= l && sum > 0) {
                sum--;
                power += tokens[r --];
            } else
                break;
        }
        return mx;
    }
};
