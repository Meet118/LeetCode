class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> f(n);
        for (int i = 0; i < n; i ++ ) {
            sort(cuboids[i].begin(), cuboids[i].end(), greater<>());
        }
        sort(cuboids.begin(), cuboids.end(), greater<>());
        int ans = 0;
        for (int i = 0; i < n; i ++ ) {
            f[i] = cuboids[i][0];
            for (int j = 0; j < i; j ++ ) {
                if (cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2])
                    f[i] = max(f[i], f[j] + cuboids[i][0]);
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
