class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> kb = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> ans;
        vector<int> a(26);
        for (int i = 0; i < kb.size(); i ++ )
            for (auto c : kb[i])
                a[c - 'a'] = i;
        for (auto s : words) {
            int x = a[tolower(s[0]) - 'a'];
            bool f = true;
            for (auto c : s) {
                c = tolower(c);
                if (a[c - 'a'] != x) {
                    f = false;
                    break;
                }
            }
            if (f)
                ans.push_back(s);
        }
        return ans;
    }
};