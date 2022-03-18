class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        set<pair<int, int>> se;
        for (auto i : dig) {
            se.insert({i[0], i[1]});
        }
        int ans = 0;
        for (auto i : artifacts) {
            int r1 = i[0], c1 = i[1], r2 = i[2], c2 = i[3];
            bool f = true;
            for (int i = r1; i <= r2 && f; i ++ )
                for (int j = c1; j <= c2; j ++ ) {
                    if (!se.count({i, j})) {
                        f = false;
                        break;
                    }
                }
            if (f)
                ans ++ ;
        }
        return ans;
    }
};
