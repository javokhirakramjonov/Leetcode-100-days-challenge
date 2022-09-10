class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int temp = prices[0];
        int sum = 0;
        for(int i = 1; i < n; ++ i) {
            if(prices[i] < prices[i - 1]) {
                sum += prices[i - 1] - temp;
                temp = prices[i];
                continue;
            }
            if(prices[i] < temp)
                temp = prices[i];
        }
        if(n > 1 && prices[n - 1] >= prices[n - 2])
            sum += prices[n - 1] - temp;
        return sum;
    }
}
