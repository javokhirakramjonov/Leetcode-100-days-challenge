class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> temp(n);
        for(int i = 0; i < n; ++ i) {
            temp[i].second = i;
            if(nums[i] == 0) {
                temp[i].first = mapping[0];
                continue;
            }
            int temp2 = nums[i];
            int pow = 1;
            while(temp2) {
                temp[i].first += pow * mapping[temp2 % 10];
                temp2 /= 10;
                pow *= 10;
            }
        }
        sort(temp.begin(), temp.end());
        vector<int> res(n);
        for(int i = 0; i < n; ++ i) {
            res[i] = nums[temp[i].second];
        }
        return res;
    }
};
