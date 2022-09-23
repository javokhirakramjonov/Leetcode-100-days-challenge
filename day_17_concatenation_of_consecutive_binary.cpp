class Solution {
public:
    
    int concatenatedBinary(int n) {
        long long res = 0, temp, x;
        for(int i = 1; i <= n; ++ i) {
            temp = i;
            x = 0;
            while(temp) {
                temp >>= 1;
                ++x;
            }
            res = ((res << x) + i) % 1000000007;
        }
        return res;
    }
};
