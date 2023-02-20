class Solution {
public:
    typedef long long ll;

    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> a, b, mp;
        for (auto x : basket1)
            a[x] ++ , mp[x] ++ ;
        for (auto x : basket2)
            b[x] ++ , mp[x] ++ ;
        for (auto [k, v] : mp)
            if (v % 2) return -1;
        vector<int> c;
        for (auto [k, v] : a) {
            if (v > mp[k] / 2)
                for (int i = 0; i < v - mp[k] / 2; i ++ )
                    c.push_back(k);
        }
        for (auto [k, v] : b) {
            if (v > mp[k] / 2)
                for (int i = 0; i < v - mp[k] / 2; i ++ )
                    c.push_back(k);
        }
        sort(c.begin(), c.end());
        int m = mp.begin()->first;
        ll ans = 0;
        for (int i = 0; i < c.size() / 2; i ++ ) {
            ans += min(c[i], m * 2);
        }
        return ans;
    }
};

