/*
tire树 + dfs
*/
class Solution {
public:
    struct Node {
        int id; //标记终点
        Node *son[26];
        Node() {
            for (int i = 0; i < 26; i ++ )
                son[i] = NULL;
            id = -1;
        }
    };

    int n, m;
    vector<vector<char>> c;
    vector<vector<int>> st;
    Node* root = new Node();

    void insert(string s, int id) {
        Node* u = root;
        for (int i = 0; i < s.size(); i ++ ) {
            int t = s[i] - 'a';
            if (!u->son[t])
                u->son[t] = new Node();
            u = u->son[t];
        }
        u->id = id;
    }

    int fx[4] = {1, -1, 0, 0}, fy[4] = {0, 0, 1, -1};
    unordered_set<int> res;

    void dfs(int x, int y, Node* node) {
        if (node->id != -1) {
            res.insert(node->id);
        }

        st[x][y] = 1;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + fx[i], b = y + fy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b] || !node->son[c[a][b] - 'a'])
                continue;
            dfs(a, b, node->son[c[a][b] - 'a']);
        }
        st[x][y] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        c = board;
        n = board.size();
        m = board[0].size();
        st.resize(n, vector<int>(m));

        for (int i = 0; i < words.size(); i ++ )
            insert(words[i], i);

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                int t = c[i][j] - 'a';
                if (root->son[t])
                    dfs(i, j, root->son[t]);
            }

        vector<string> ans;
        for (auto i : res)
            ans.push_back(words[i]);
        return ans;
    }
};