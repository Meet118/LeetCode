class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for (char c : number)
            if (c != ' ' && c != '-')
                s += c;
        int n = s.size();
        string ans;
        int i;
        for (i = 0; i + 4 < n; i += 3) {
            ans += s.substr(i, 3);
            ans += '-';
        }
        if (n % 3 != 0)
            for (; i + 2 < n; i += 2) {
                ans += s.substr(i, 2);
                ans += '-';
            }
        while (i < n) ans += s[i ++ ];
        return ans;
    }
};
