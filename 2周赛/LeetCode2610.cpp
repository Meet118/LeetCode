class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = 210;
        vector<int> cnt(n);
        for (auto x : nums) cnt[x] ++ ;
        vector<vector<int>> ans;
        while (true) {
            vector<int> t;
            for (int i = 1; i < n; i ++ )
                if (cnt[i] > 0) {
                    t.push_back(i);
                    cnt[i] -- ;
                }
            if (t.size() == 0) break;
            ans.push_back(t);
        }
        return ans;
    }
};

