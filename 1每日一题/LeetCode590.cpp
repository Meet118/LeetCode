class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<pair<Node*, int>> stk;
        stk.push({root, 0});
        while (stk.size()) {
            auto t = stk.top();
            stk.pop();
            if (t.first == nullptr)
                continue;
            if (t.second == t.first->children.size())
                ans.push_back(t.first->val);
            if (t.second < t.first->children.size()) {
                stk.push({t.first, t.second + 1});
                stk.push({t.first->children[t.second], 0});
            }   
        }
        return ans;
    }
};
