//trie+bfs
class WordDictionary {
public:
    struct Tree {
        int cnt = 0;
        Tree* child[26];
    }*root;

    WordDictionary() {
        root = new Tree();
    }
    
    void addWord(string word) {
        Tree* p = root;
        for (int i = 0; i < word.size(); i ++ ) {
            int u = word[i] - 'a';
            if (!p->child[u])
                p->child[u] = new Tree();
            p = p->child[u];
        }
        p->cnt ++ ;
    }
    
    bool search(string word) {
        queue<pair<Tree*, int>> q;
        q.push({root, 0});

        int n = word.size();
        while (q.size()) {
            auto t = q.front();
            q.pop();
            auto p = t.first;
            int c = t.second;
            if (c == n && p->cnt > 0)
                return true;
            else if (c == n)
                continue;
            if (word[c] != '.') {
                if (!p->child[word[c] - 'a']) {
                    if (q.size() == 0)
                        return false;
                    else
                        continue;
                }
                if (c < n)
                    q.push({p->child[word[c] - 'a'], c + 1});
            }
            else {
                for (int i = 0; i < 26; i ++ )
                    if (p->child[i] && c < n)
                        q.push({p->child[i], c + 1});
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */