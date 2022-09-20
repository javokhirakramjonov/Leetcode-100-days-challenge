class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        short a = 0;
        for(int& x: position)
            a += x & 1;
        return (int)((a << 1) < position.size() ? a : position.size() - a);
    }
};
