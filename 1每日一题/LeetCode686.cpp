class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        while ((int)s.size() < b.size())
            s += a;
        s += a;
        int n = a.size(), m = b.size();
        vector<int> ne(m + 1);
        b = ' ' + b;
        s = ' ' + s;
        for (int i = 2, j = 0; i <= m; i ++ ) {
            while (j && b[i] != b[j + 1]) j = ne[j];
            if (b[i] == b[j + 1])
                j ++ ;
            ne[i] = j;
        }
        for (int i = 1, j = 0; i < s.size(); i ++ ) {
            while (j && s[i] != b[j + 1]) j = ne[j];
            if (s[i] == b[j + 1])
                j ++ ;
            if (j == m)
                return (i + a.size() - 1) / a.size();
        }

        return -1;
    }
};
