/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string ans = "";
    TreeNode* root;

    void dfs(TreeNode* u) {
        if (!u)
            return;
        if (u != root)
            ans += '(';
        ans += to_string(u->val);
        dfs(u->left);
        if (!u->left && u->right)
            ans += "()";
        dfs(u->right);
        if (u != root)
            ans += ')';
    }

    string tree2str(TreeNode* _root) {
        root = _root;
        dfs(root);
        return ans;
    }
};
