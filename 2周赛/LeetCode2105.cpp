class Solution {
public:
    int minimumRefill(vector<int>& p, int ca, int cb) {
        int n = p.size();
        int i = 0, j = n - 1;
        int ans = 0;
        int a = ca, b = cb;
        while (i < j) {
            if (a < p[i])
                ans ++ , a = ca;
            if (b < p[j])
                ans ++ , b = cb;
            a -= p[i];
            b -= p[j];
            i ++ , j -- ;
        }
        if (i == j) {
            if (a == b || a > b) {
                if (a < p[i])
                    ans ++ ;
            }
            else {
                if (b < p[i])
                    ans ++ ;
            }
        }
        return ans;
    }
};

