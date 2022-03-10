//使用栈模拟，每次记录当前节点和已遍历过的节点数量
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<pair<Node*, int>> stk;
        stk.push({root, 0});
        while (stk.size()) {
            auto t = stk.top();
            stk.pop();
            if (t.first == nullptr)
                continue;
            if (t.second == 0)
                ans.push_back(t.first->val);
            if (t.second < t.first->children.size()) {
                stk.push({t.first, t.second + 1});
                stk.push({t.first->children[t.second], 0});
            }
        }
        return ans;
    }
};
//递归
class Solution {
public:
    vector<int> ans;

    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }

    void dfs(Node* u) {
        if (!u) return;
        ans.push_back(u->val);
        for (auto i : u->children)
            dfs(i);
    }
};
