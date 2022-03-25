class Solution {
public:
    int f(int pre, int n) {
        int p = 1;
        int res = 0;
        string a = to_string(pre), b = to_string(n);
        for (int i = 0; i < b.size() - a.size(); i ++ ) {
            res += p;
            p *= 10;
        }
        b = b.substr(0, a.size());
        if (a == b)
            res += n - pre * p + 1;
        else if (a < b)
            res += p;
        return res;
    }

    int findKthNumber(int n, int k) {
        int p = 1;
        while (k > 1) {
            int cnt = f(p, n);
            if (cnt < k) {
                k -= cnt;
                p ++ ;
            }
            else {
                k -- ;
                p *= 10;
            }
        }
        return p;
    }
};
