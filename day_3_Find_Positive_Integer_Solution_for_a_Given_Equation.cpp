/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int l = 1, r = 1000, m;
        for(int i = 1; i < 1001; ++ i) {
            l = 1;
            while(l < r) {
                m = l + (r - l) / 2;
                int temp = customfunction.f(i, m);
                if(temp < z)
                    l = m + 1;
                else if(temp == z) {
                    l = m;
                    break;
                }
                else 
                    r = m;
            }
            if(customfunction.f(i, l) == z) {
                vector<int> x = {i, l};
                res.push_back(x);
            }
        }
        return res;
    }
};
