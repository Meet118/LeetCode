class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> se {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int a = 0, b = 0;
        for (int i = 0, j = n / 2; j < n; i ++ , j ++ ) {
            if (se.count(s[i] ^ 32) || se.count(s[i])) a ++ ;
            if (se.count(s[j] ^ 32) || se.count(s[j])) b ++ ;
        }

        return a == b;
    }
};
