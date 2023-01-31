class Solution {
public:
    typedef long long ll;
    
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        if (n == 1) return 0;
        vector<ll> a;
        for (int i = 0; i < n - 1; i ++ )
            a.push_back(w[i] + w[i + 1]);
        sort(a.begin(), a.end());
        ll t1 = 0, t2 = 0;
        // 最大的k - 1个数
        for (int i = a.size() - 1; i >= a.size() - k + 1 && i >= 0; i -- )
            t1 += a[i];
        // 最小的k - 1个数
        for (int i = 0; i < k - 1 && i < a.size(); i ++ )
            t2 += a[i];
        return t1 - t2;
    }
};

