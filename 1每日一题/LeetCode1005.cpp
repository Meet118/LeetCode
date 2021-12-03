class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int m = 1e9;
        for (int x : nums) {
            cnt[x] ++ ;
            m = min(m, abs(x));
        }
        for (int i = -100; i < 0 && k; i ++ ) {
            while (cnt[i] > 0 && k) {
                cnt[i] -- ;
                cnt[-i] ++ ;
                k -- ;
            }
        }
        int ans = 0;
        for (int i = -100; i <= 100; i ++ ) {
            if (cnt.count(i))
                ans += i * cnt[i];
        }
        if (k % 2)
            ans -= m * 2;
        return ans;
    }
};
