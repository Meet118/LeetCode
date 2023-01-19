class Solution {
public:
    typedef long long ll;

    long long countGood(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();
        unordered_map<int, ll> cnt;
        ll c = 0;
        for (int l = 0, r = 0; r < n; r ++ ) {
            c += cnt[nums[r]];
            cnt[nums[r]] ++ ;
            while (l < r && c >= k) {
                cnt[nums[l]] -- ;
                c -= cnt[nums[l]];
                l ++ ;
            }
            ans += l;
        }
        return ans;
    }
};

