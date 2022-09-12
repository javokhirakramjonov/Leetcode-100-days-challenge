class Solution {
public:
    int superPow(int aa, vector<int>& b) {
        long long a = aa;
        int res = 1;
        int n = 0;
        int pow10 = 1;
        for(int i = b.size() - 1 ; i >= 0; -- i){
            (n += (b[i] * pow10)) %= 1140;
            (pow10 *= 10) %= 1140;
        }
        n %= 1140;
        while(n) {
            if(n & 1)
                res = (res * a) % 1337;
            a = (a * a) % 1337;
            n >>= 1;
        }
        return res;
    }
};
