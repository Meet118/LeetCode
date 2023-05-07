class Solution {
public:
    typedef long long ll;
    
    vector<long long> distance(vector<int>& a) {
        unordered_map<int, vector<int>> mp;
        int n = a.size();
        for (int i = 0; i < n; i ++ ) {
            mp[a[i]].push_back(i);
        }
        vector<ll> ans(n);
        for (auto& [k, v] : mp) {
            int m = v.size();
            if (m == 1) continue;
            ll s = 0;
            for (int i = 0; i < m; i ++ )
                s += v[i];
            ll t = 0;
            for (int i = 0; i < m; i ++ ) {
                s -= v[i];
                ans[v[i]] = ((ll)v[i] * i) - t + (s - (ll)v[i] * (m - i - 1));
                t += v[i];
            }
        }
        return ans;
    }
};

