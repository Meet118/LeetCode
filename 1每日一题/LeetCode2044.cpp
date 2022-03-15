class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxt = 0, ans = 0;
        for (int i = 1; i < (1 << n); i ++ ) {
            int t = 0;
            for (int j = 0; j < n; j ++ ) {
                if ((i >> j & 1) == 1)
                    t |= nums[j];
            }
            if (t > maxt) {
                maxt = t;
                ans = 1;
            }
            else if (t == maxt)
                ans ++ ;
        }
        return ans;
    }
};
