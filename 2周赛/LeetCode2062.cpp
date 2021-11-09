class Solution {
public:
    int countVowelSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int len = 5; len <= n; len ++ )
            for (int l = 0; l + len - 1 < n; l ++ ) {
                if (check(s, l, len))
                    ans ++ ;
            }
        return ans;
    }
    
    bool check(string& s, int l, int n) {
        unordered_set<char> se;
        for (int i = l; i < l + n; i ++ )
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                se.insert(s[i]);
                if (se.size() > 5)
                    return false;
            }
            else
                return false;
        return se.size() == 5;
    }
};
