class MapSum {
public:
    struct Node {
        int val;
        Node* son[26];
    }*root;

    unordered_map<string, int> mp;

    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        int v;
        if (mp.count(key)) {
            v = val - mp[key];
        }
        else {
            v = val;
        }
        mp[key] = val;
        Node* p = root;
        for (int i = 0; i < key.size(); i ++ ) {
            int u = key[i] - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
            p->val += v;
        }
    }
    
    int sum(string prefix) {
        Node* p = root;
        for (int i = 0; i < prefix.size(); i ++ ) {
            int u = prefix[i] - 'a';
            if (!p->son[u])
                return 0;
            p = p->son[u];
        }
        return p->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */