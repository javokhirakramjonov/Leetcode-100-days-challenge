class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> mp, temp;
        int sum = 1;
        for(int i = 0; i < s.size(); ++ i) {
            if(mp[s[i]] > 0) {
                sum++;
                mp = temp;
            }
                mp[s[i]] = 1;
        }
        return sum;
    }
};
