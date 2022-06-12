class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string w : words)
            if (check(w, pattern))
                ans.push_back(w);
        return ans;
    }

    bool check(string a, string b) {
        int n = a.size();
        unordered_map<char, char> mp;
        unordered_set<char> se;
        int j = 0;
        for (int i = 0; i < n; i ++ ) {
            if (!mp.count(b[j])) {
                mp[b[j]] = a[i];
                if (se.count(a[i]))
                    break;
                se.insert(a[i]);
            }
            else {
                if (mp[b[j]] != a[i])
                    break;
            }
            j ++ ;
        }
        return j == n;
    }
};
