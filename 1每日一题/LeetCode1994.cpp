typedef long long ll;
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> cnt(31);
        int mod = 1e9 + 7;
        for (int i : nums)
            cnt[i] ++ ;
        vector<int> f(1 << 10);
        f[0] = 1;
        for (int i = 2; i <= 30; i ++ ) {
            if (cnt[i] == 0)
                continue;
            int t = 0, x = i;
            bool flag = true;
            for (int j = 0; j < p.size(); j ++ ) {
                if (x % p[j] == 0) {
                    t |= (1 << j);
                    x /= p[j];
                }
                if (x % p[j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;
            for (int j = (1 << 10) - 1; j >= 0; j -- ) {
                if ((j & t) == t)
                    f[j] = ((ll)f[j] + (ll)f[j ^ t] * cnt[i] % mod) % mod;
            }
        }
        int ans = 0;
        for (int i = 1; i < (1 << 10); i ++ )
            ans = (ans + f[i]) % mod;
        for (int i = 0; i < cnt[1]; i ++ )
            ans = ans * 2 % mod;
        return ans;
    }
};
