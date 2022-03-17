class Solution {
public:
    struct Tree {
        bool is_end;
        vector<Tree*> ch;
        Tree () {
            ch.resize(26);
            is_end = false;
        } 
    }*root;

    void ins(string s) {
        Tree* u = root;
        for (int i = 0; i < s.size(); i ++ ) {
            int t = s[i] - 'a';
            if (!u->ch[t]) u->ch[t] = new Tree();
            u = u->ch[t];
        }
        u->is_end = true;
    }

    bool check(string s) {
        Tree* u = root;
        for (int i = 0; i < s.size(); i ++ ) {
            int t = s[i] - 'a';
            if (!u->ch[t])
                return false;
            u = u->ch[t];
            if (!u->is_end)
                return false;
        }
        return true;
    }

    string longestWord(vector<string>& words) {
        root = new Tree();
        for (auto s : words)
            ins(s);
        string ans;
        for (auto s : words)
            if (check(s)) {
                if (s.size() > ans.size() || s.size() == ans.size() && s < ans)
                    ans = s;
            }
        return ans;
    }
};
