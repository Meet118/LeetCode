class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> f;
        vector<vector<int>> a(n, vector<int>(n, 1));
        f.resize(n, vector<int>(n, 0));
        for (auto e : mines) {
            a[e[0]][e[1]] = 0;
        }
        //左
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0, s = 0; j < n; j ++ ) {
                if (a[i][j] == 1) s ++ ;
                else s = 0;
                f[i][j] = s;
            }
        }
        //右
        for (int i = 0; i < n; i ++ ) {
            for (int j = n - 1, s = 0; j >= 0; j -- ) {
                if (a[i][j] == 1) s ++ ;
                else s = 0;
                f[i][j] = min(f[i][j], s);
            }
        }
        //上
        for (int j = 0; j < n; j ++ ) {
            for (int i = 0, s = 0; i < n; i ++ ) {
                if (a[i][j] == 1) s ++ ;
                else s = 0;
                f[i][j] = min(f[i][j], s);
            }
        }
        //下
        for (int j = 0; j < n; j ++ ) {
            for (int i = n - 1, s = 0; i >= 0; i -- ) {
                if (a[i][j] == 1) s ++ ;
                else s = 0;
                f[i][j] = min(f[i][j], s);
            }
        }
        int ans = 0;  
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (a[i][j]) {
                    ans = max(ans, f[i][j]);
                }
            }
        }

        return ans;
    }
};
