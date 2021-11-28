class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for (auto c : p)
            mp[c] ++ ;
        vector<int> ans;
        int tot = mp.size(), n = s.size(), m = p.size();
        for (int i = 0, j = 0, cnt = 0; i < n; i ++ ) {
            if ( -- mp[s[i]] == 0)
                cnt ++ ;
            if (i - j + 1 > m) {
                if (mp[s[j]] == 0) cnt -- ;
                mp[s[j]] ++ ;
                j ++ ;
            }
            if (cnt == tot) ans.push_back(j);
        }
        return ans;
    }
};
