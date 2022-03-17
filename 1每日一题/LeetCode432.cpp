class AllOne {
public:
    struct Node {
        Node *left, *right;
        int val;
        unordered_set<string> se;
        Node (int _val) {
            val = _val;
            left = right = nullptr;
        }
    }*left, *right;
    unordered_map<string, Node*> mp;

    AllOne() {
        left = new Node(INT_MIN);
        right = new Node(INT_MAX);
        left->right = right;
        right->left = left;
    }
    
    //在右边加入节点
    Node* add_to_right(string s, Node* u, int val) {
        if (u->right->val == val) {
            u->right->se.insert(s);
        }
        else {
            auto t = new Node(val);
            t->se.insert(s);
            t->right = u->right;
            t->left = u;
            u->right->left = t;
            u->right = t;
        }
        return u->right;
    }

    //在左边加入节点
    Node* add_to_left(string s, Node* u, int val) {
        if (u->left->val == val) {
            u->left->se.insert(s);
        }
        else {
            auto t = new Node(val);
            t->se.insert(s);
            t->left = u->left;
            t->right = u;
            u->left->right = t;
            u->left = t;
        }
        return u->left;
    }

    //移除节点
    void remove(Node* u) {
        u->left->right = u->right;
        u->right->left = u->left;
        delete u;
    }

    void inc(string key) {
        if (!mp.count(key)) {
            mp[key] = add_to_right(key, left, 1);
        }
        else {
            auto t = mp[key];
            t->se.erase(key);
            mp[key] = add_to_right(key, t, t->val + 1);
            if (t->se.empty())
                remove(t);
        }
    }
    
    void dec(string key) {
        if (!mp.count(key))
            return;
        auto t = mp[key];
        t->se.erase(key);
        if (t->val - 1 > 0)
            mp[key] = add_to_left(key, t, t->val - 1);
        else
            mp.erase(key);
        if (t->se.empty())
            remove(t);
    }
    
    string getMaxKey() {
        if (right->left != left)
            return *right->left->se.begin();
        return "";
    }
    
    string getMinKey() {
        if (left->right != right)
            return *left->right->se.begin();
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
