class Solution {
public:
    struct Tree {
        int end;
        Tree* son[26];
    }*root;

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.size() < b.size();
        });
        vector<string> ans;
        root = new Tree();
        for (string s : words) {
            if (s == "") continue;
            if (dfs(s, 0))
                ans.push_back(s);
            else
                insert(s);
        }

        return ans;
    }

    bool dfs(string s, int st) {
        Tree* u = root;
        for (int i = st; i < s.size(); i ++ ) {
            int t = s[i] - 'a';
            if (u->son[t]) u = u->son[t];
            else return false;
            if (u->end) {
                if (dfs(s, i + 1))
                    return true;
            }
        }
        if (st == s.size())
            return true;
        return false;
    }

    void insert(string s) {
        Tree* u = root;
        for (int i = 0; i < s.size(); i ++ ) {
            int t = s[i] - 'a';
            if (!u->son[t]) u->son[t] = new Tree();
            u = u->son[t];
        }
        u->end = 1;
    }
};
