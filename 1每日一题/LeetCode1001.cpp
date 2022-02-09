class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<pair<int, int>, int> mp;
        unordered_map<int, int> r, c, dg, udg;
        for (auto i : lamps) {
            if (mp.count({i[0], i[1]}))
                continue;
            mp[{i[0], i[1]}] ++ ;
            r[i[0]] ++ ;
            c[i[1]] ++ ;
            dg[i[0] - i[1]] ++ ;
            udg[i[0] + i[1]] ++ ;
        }
        vector<int> ans;
        for (auto i : queries) {
            if (r[i[0]] > 0 || c[i[1]] > 0 || dg[i[0] - i[1]] > 0 || udg[i[0] + i[1]] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);
            for (int x = i[0] - 1; x <= i[0] + 1; x ++ )
                for (int y = i[1] - 1; y <= i[1] + 1; y ++ ) {
                    if (x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    if (mp[{x, y}] > 0) {
                        mp[{x, y}] -- ;
                        r[x] -- ;
                        c[y] -- ;
                        dg[x - y] -- ;
                        udg[x + y] -- ;
                    }
                }
        }
        return ans;
    }
};
