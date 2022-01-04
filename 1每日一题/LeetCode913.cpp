class Solution {
public:
    vector<vector<int>> g;
    int n;
    vector<vector<vector<int>>> f;

    int dp(int k, int i, int j) {
        int& v = f[k][i][j];
        if (v != -1) return v;
        if (k > 2 * n) return v = 0; 
        if (i == 0) return v = 1; //老鼠赢
        if (i == j) return v = 2; //猫赢

        int draw = 0; //是否可能平局
        if (k % 2 == 0) { //老鼠走
            for (int x : g[i]) {
                int t = dp(k + 1, x, j);
                if (t == 1) return v = 1; //先考虑赢
                if (t == 0) draw = 1; //再考虑平局
            }
            if (draw) return v = 0;
            return v = 2; //否则输
        }
        else { //猫走
            for (int x : g[j]) {
                if (x == 0) continue;
                int t = dp(k + 1, i, x);
                if (t == 2) return v = 2;
                if (t == 0) draw = 1;
            }
            if (draw) return v = 0;
            return v = 1;
        }
    }

    int catMouseGame(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        f.resize(n * 2 + 2, vector<vector<int>>(n, vector<int>(n, -1)));
        return dp(0, 1, 2);
    }
};
