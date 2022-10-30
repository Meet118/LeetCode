class Solution {
public:
    vector<string> ans;

    void dfs(int u, string& s) {
        ans.push_back(s);
        for (int i = u; i < s.size(); i ++ ) {
            if (isalpha(s[i])) {
                s[i] ^= 32;
                dfs(i + 1, s);
                s[i] ^= 32;
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        dfs(0, s);
        return ans;
    }
};
