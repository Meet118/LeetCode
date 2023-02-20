class Solution {
public:
    typedef long long ll;
    
    ll calc(vector<int> &a, ll x) {
        ll res = 0;
        int n = a.size();
        for (int i = 1; i < a.size(); i ++ ) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (a[i] + a[mid] <= x) l = mid;
                else r = mid - 1;
            }
            if (a[i] + a[l] <= x)
                res += l + 1;
        }
        return res;
    }
    
    long long countFairPairs(vector<int>& a, int lower, int upper) {
        sort(a.begin(), a.end());
        return calc(a, upper) - calc(a, lower - 1);
    }
};

