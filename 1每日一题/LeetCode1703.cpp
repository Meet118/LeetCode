class Solution {
public:
    typedef long long ll;

    int minMoves(vector<int>& nums, int k) {
        vector<int> a;
        for (int i = 0; i < nums.size(); i ++ )
            if (nums[i] == 1) a.push_back(i - a.size() - 1);
        int n = a.size();
        vector<ll> s(n + 1);
        for (int i = 0; i < a.size(); i ++ )
            s[i + 1] = s[i] + a[i];
        ll ans = 1e18;
        for (int i = k; i <= n; i ++ ) {
            int l = i - k + 1, r = i;
            int mid = (l + r) / 2;
            ll x = a[mid - 1];
            ll left = x * (mid - l + 1) - (s[mid] - s[l - 1]);
            ll right = (s[r] - s[mid]) - x * (r - mid);
            ans = min(ans, left + right);
        }
        return ans;
    }
};
