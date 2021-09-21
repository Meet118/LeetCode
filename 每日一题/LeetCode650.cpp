//分解质因数
/*
分段可以看做各段相乘的结果
*/
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i <= n / i; i ++ ) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        if (n > 1)
            ans += n;
        return ans;
    }
};

/* ================================================================= */
//动态规划
class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 1e9));

        f[1][0] = 0;
        for (int i = 1; i <= n; i ++ ) {
            //复制
            for (int j = 0; j < i; j ++ )
                f[i][i] = min(f[i][i], f[i][j] + 1);

            //粘贴
            for (int cnt = 1; i + cnt <= n; cnt ++ )
                f[i + cnt][cnt] = min(f[i + cnt][cnt], f[i][cnt] + 1);
        }
        int ans = 1e9;
        for (int i = 0; i <= n; i ++ )
            ans = min(ans, f[n][i]);
        return ans;
    }
};