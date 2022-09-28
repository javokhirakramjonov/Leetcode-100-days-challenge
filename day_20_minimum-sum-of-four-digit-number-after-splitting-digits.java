class Solution {
    public int minimumSum(int num) {
        int a = num % 10;
        int b = num / 10 % 10;
        int c = num / 100 % 10;
        int d = num / 1000 % 10;
        int mn, w, ans = 0;
        mn = a;
        w = 1;
        if(b < mn) {
            w = 2;
            mn = b;
        }
        if(c < mn) {
            w = 3;
            mn = c;
        }
        if(d < mn) {
            w = 4;
            mn = d;
        }
        a = w == 1 ? 9 : a;
        b = w == 2 ? 9 : b;
        c = w == 3 ? 9 : c;
        d = w == 4 ? 9 : d;
        ans = ans * 10 + mn;
        mn = a;
        w = 1;
        if(b < mn) {
            w = 2;
            mn = b;
        }
        if(c < mn) {
            w = 3;
            mn = c;
        }
        if(d < mn) {
            w = 4;
            mn = d;
        }
        a = w == 1 ? 9 : a;
        b = w == 2 ? 9 : b;
        c = w == 3 ? 9 : c;
        d = w == 4 ? 9 : d;
        ans = ans * 10 + mn;
        mn = a;
        w = 1;
        if(b < mn) {
            w = 2;
            mn = b;
        }
        if(c < mn) {
            w = 3;
            mn = c;
        }
        if(d < mn) {
            w = 4;
            mn = d;
        }
        a = w == 1 ? 9 : a;
        b = w == 2 ? 9 : b;
        c = w == 3 ? 9 : c;
        d = w == 4 ? 9 : d;
        ans = ans * 10 + mn;
        mn = a;
        w = 1;
        if(b < mn) {
            w = 2;
            mn = b;
        }
        if(c < mn) {
            w = 3;
            mn = c;
        }
        if(d < mn) {
            w = 4;
            mn = d;
        }
        a = w == 1 ? 9 : a;
        b = w == 2 ? 9 : b;
        c = w == 3 ? 9 : c;
        d = w == 4 ? 9 : d;
        ans = ans * 10 + mn;
        int aa = ans / 1000 * 10 + ans / 10 % 10;
        int bb = ans / 100 % 10 * 10 + ans % 10;
        return aa + bb;
    }
}
