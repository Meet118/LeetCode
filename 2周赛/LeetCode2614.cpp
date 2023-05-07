class Solution {
public:
    bool isp(int x) {
        if (x == 1) return false;
        for (int i = 2; i * i <= x; i ++ ) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& a) {
        int m = a.size();
        int ans = 0;
        for (int i = 0; i < m; i ++ ) {
            if (isp(a[i][i]))
                ans = max(ans, a[i][i]);
            if (isp(a[i][m - i - 1]))
                ans = max(ans, a[i][m - i - 1]);
        }
        return ans;
    }
};

