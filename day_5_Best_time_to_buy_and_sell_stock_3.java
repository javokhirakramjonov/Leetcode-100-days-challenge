class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] a = new int[n];
        int[] b = new int[n];
        int mn = prices[0], mx = prices[n - 1];
        for(int i = 1; i < n; ++ i) {
            a[i] = max(a[i - 1], prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        for(int i = n - 2; i >= 0; -- i) {
            b[i] = max(b[i + 1], mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        mx = 0;
        for(int i = 0; i < n; ++ i) {
            mx = max(mx, a[i] + (i + 1 < n ? b[i + 1] : 0));
        }
        return mx;
    }
    
    private int min(int a, int b) {
        return a < b ? a : b;
    }
    
    private int max(int a, int b) {
        return a > b ? a : b;
    }
}
