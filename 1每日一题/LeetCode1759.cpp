typedef long long ll;

class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        const int mod = 1e9 + 7;
        int n = s.size();
        for (int i = 0, j; i < n; i ++ ) {
            j = i;
            while (j < n && s[i] == s[j]) j ++ ;
            int k = j - i;
            ans = (ans + (ll)k * (k + 1) / 2) % mod;
            i = j - 1;
        }
        return ans;
    }
};
