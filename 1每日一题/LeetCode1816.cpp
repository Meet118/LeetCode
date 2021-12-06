class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int n = s.size(), i = 0;
        while (k -- ) {
            string t = "";
            while (i < n && s[i] != ' ')
                t += s[i ++ ];
            i ++ ;
            ans += t;
            if (k)
                ans += ' ';
        }
        return ans;
    }
};
