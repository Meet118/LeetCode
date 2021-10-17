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
    int ans;
    int cur;

    void dfs(TreeNode* u, int k) {
        if (!u)
            return;
        dfs(u->left, k);
        cur ++ ;
        if (cur == k) {
            ans = u->val;
            return;
        }
        dfs(u->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        cur = 0;
        dfs(root, k);
        return ans;
    }
};