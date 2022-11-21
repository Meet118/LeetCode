class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> f(110, vector<double>(110));
        f[0][0] = poured;
        for (int i = 0; i <= query_row; i ++ ) {
            for (int j = 0; j <= i; j ++ ) {
                if (f[i][j] <= 1) continue;
                double down = (f[i][j] - 1) / 2;
                f[i + 1][j] += down;
                f[i + 1][j + 1] += down;
            }
        }
        return min(1.0, f[query_row][query_glass]);
    }
};
