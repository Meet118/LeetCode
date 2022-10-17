class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> q(n);
        int hh = 0, tt = -1;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i ++ ) {
            q[ ++ tt] = fruits[i];
            mp[q[tt]] ++ ;
            while (hh < tt && mp.size() > 2) {
                mp[q[hh]] -- ;
                if (mp[q[hh]] == 0) mp.erase(q[hh]);
                hh ++ ;
            }
            ans = max(ans, tt - hh + 1);
        }
        return ans;
    }
};
