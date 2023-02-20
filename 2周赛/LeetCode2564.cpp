class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i ++ )
            for (int j = i; j < n; j ++ ) {
                string t = s.substr(i, j - i + 1);
                if (j - i + 1 >= 32) break;
                if (!mp.count(t))
                    mp[t] = i;
            }
        for (auto x : queries) {
            int t = x[0] ^ x[1];
            string a;
            while (t) {
                if (t & 1) a = '1' + a;
                else a = '0' + a;
                t >>= 1;
            }
            if (a.size() == 0) a = "0";
            if (mp.count(a)) ans.push_back({mp[a], mp[a] + (int)a.size() - 1});
            else ans.push_back({-1, -1});
        }
        return ans;
    }
};

