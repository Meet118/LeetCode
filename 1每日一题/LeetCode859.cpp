class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int a = -1, b = -1, c = 0;
        for (int i = 0; i < n; i ++ ) {
            if (s[i] != goal[i] && a == -1 && c == 0)
                a = i, c ++ ;
            else if (s[i] != goal[i] && b == -1 && c == 1)
                b = i, c ++ ;
        }
        if (c == 0) {
            unordered_set<char> se;
            for (auto c : s) {
                if (se.count(c))
                    return true;
                se.insert(c);
            }
        }
        if (c == 2) {
            swap(s[a], s[b]);
            return s == goal;
        }
        return false;
    }
};
