class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i ++ ) a[i] = i;       
        while (true) {
            change(a);
            ans ++ ;
            bool f = true;
            for (int i = 0; i < n; i ++ )
                if (a[i] != i) {
                    f = false;
                    break;
                }
            if (f) break;
        }
        return ans;
    }

    void change(vector<int> &a) {
        int n = a.size();
        vector<int> b;
        b = a;
        for (int i = 0; i < n; i ++ ) {
            if (i % 2 == 0) a[i] = b[i / 2];
            else a[i] = b[n / 2 + (i - 1) / 2];
        }
    }
};
