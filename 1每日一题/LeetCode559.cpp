/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans = 0;

    int maxDepth(Node* root) {
        if (!root) return 0;
        dfs(root, 1);
        return ans;
    }

    void dfs(Node* u, int d) {
        ans = max(ans, d);
        if (u->children.size() == 0)
            return;
        for (auto i : u->children)
            dfs(i, d + 1);
    }
};
