class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int m = 0;
        for (int x : nums)
            m = max(x, m);
        int n = nums.size();
        int l = 0, r = m;
        while (l < r) {
            int mid = l + r >> 1;
            vector<int> f(n + 1); //f[i]表示前i个房屋，不超过mid的最多房屋数
            for (int i = 1; i <= n; i ++ ) {
                int x = nums[i - 1];
                if (x > mid) f[i] = f[i - 1]; //不能偷当前房屋
                else {
                    if (i > 1)
                        f[i] = max(f[i], f[i - 2] + 1); //不偷和偷两种情况
                    else
                        f[i] = 1; //偷
                }
            }
            if (f[n] >= k) r = mid; //能够满足条件，mid越大越能满足
            else l = mid + 1;
        }
        return l;
    }
};

