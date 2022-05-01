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
    void dfs(TreeNode* u, vector<int>& a) {
        if (!u) return;
        dfs(u->left, a);
        a.push_back(u->val);
        dfs(u->right, a);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        int i = 0, j = 0;
        vector<int> ans;
        while (i < a.size() || j < b.size()) {
            if (i < a.size() && j < b.size() && a[i] <= b[j] || i < a.size() && j == b.size())
                ans.push_back(a[i ++ ]);
            else
                ans.push_back(b[j ++ ]);
        }
        return ans;
    }
};
