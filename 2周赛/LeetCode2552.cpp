class Solution {
public:
    typedef long long ll;
    
    long long countQuadruplets(vector<int>& a) {
        int n = a.size();
        const int N = 4010;
        vector<vector<int>> l, r;
        l.resize(n, vector<int>(N));
        r.resize(n, vector<int>(N));
        for (int i = 0; i < n; i ++ ) {
            if (i)
                l[i] = l[i - 1];
            for (int j = a[i] + 1; j < N; j ++ )
                l[i][j] ++ ;
        }
        for (int i = n - 1; i >= 0; i -- ) {
            if (i < n - 1)
                r[i] = r[i + 1];
            for (int j = a[i] - 1; j >= 0; j -- )
                r[i][j] ++ ;
        }
        ll ans = 0;
        for (int i = 1; i < n; i ++ )
            for (int j = i + 1; j < n - 1; j ++ ) {
                if (a[i] > a[j]) {
                    ans += l[i - 1][a[j]] * r[j + 1][a[i]];
                }
            }
        return ans;
    }
};

