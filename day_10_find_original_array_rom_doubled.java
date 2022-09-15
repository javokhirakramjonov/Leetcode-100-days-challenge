class Solution {
    public int[] findOriginalArray(int[] changed) {
        if(changed.length % 2 == 1)
            return new int[]{};
        int[] temp = new int[100_001];
        for(int x: changed)
            temp[x] ++;
        int n = changed.length;
        int[] ans = new int[n / 2];
        int pos = 0;
        if(temp[0] % 2 == 1)
            return new int[]{};
        pos = temp[0] / 2;
        for (int i = 0; i < pos; ++i)
            ans[i] = 0;
        temp[0] = 0;
        for (int i = 2; i < 100_001; i += 2) {
            while (temp[i] > 0 && temp[i / 2] > 0) {
                temp[i]--;
                temp[i / 2]--;
                ans[pos++] = i / 2;
            }
        }
        for (int i = 0; i < 100_001; ++i)
            if (temp[i] > 0)
                return new int[]{};
        return ans;
    }
}
