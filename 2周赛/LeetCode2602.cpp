class Solution {
public:
    typedef long long ll;
    
    vector<long long> minOperations(vector<int>& a, vector<int>& queries) {
        sort(a.begin(), a.end());
        vector<ll> ans;
        int n = a.size();
        vector<ll> s(n + 1);
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i - 1];
        for (ll x : queries) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (a[mid] >= x) r = mid;
                else l = mid + 1;
            }
            if (x >= a[n - 1]) l = n;
            ll res = (l * x - s[l]) + (s[n] - s[l] - (n - l) * x);
            ans.push_back(res);
        }
        return ans;
    }
};

