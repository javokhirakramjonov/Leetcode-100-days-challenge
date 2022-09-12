class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool desc = true;
        for(int i = 0; i + 1 < n; ++ i) {
            if(nums[i] < nums[i + 1]) {
                desc = false;
                break;
            }
        }
        if(desc) {
            for(int i = 0, x; i < n / 2; ++ i) {
                x = nums[i];
                nums[i] = nums[n - i - 1];
                nums[n - i - 1] = x;
            }
            cout << "desc";
            return;
        }
        int x;
        for(int i = n - 2; i >= 0; -- i) {
            if(nums[i] < nums[i + 1]) {
                x = i;
                break;
            }
        }
        int xx = n;
        for(int i = n - 1; i > x; -- i)
            if(nums[i] > nums[x] && (xx == n || nums[i] < nums[xx]))
                xx = i;
        cout << x << ' ' << xx;
        int temp = nums[x];
        nums[x ++] = nums[xx];
        nums[xx] = temp;
        xx = n - 1;
        while(x < xx) {
            temp = nums[x];
            nums[x] = nums[xx];
            nums[xx] = temp;
            x ++;
            xx --;
        }
    }
};
