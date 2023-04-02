class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int m) {
        vector<int> cnt(m);
        for (auto x : nums)
            cnt[(x % m + m) % m] ++ ;
        int ans = 0;
        while (cnt[ans % m] -- ) {
            ans ++ ;
        }
        return ans;
    }
};

