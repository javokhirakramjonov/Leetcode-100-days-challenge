class Solution {
public:
    int arrangeCoins(long long n) {
        long long l = 0;
        long long r = n;
        long long m;
        while(l < r) {
            m = l + (r - l) / 2;
            if(m * (m + 1) < 2 * n)
                l = m + 1;
            else
                r = m;
        }
        if(l * (l + 1) > n * 2)
            return l - 1;
        return l;
    }
};
