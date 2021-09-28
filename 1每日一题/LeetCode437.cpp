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
//用哈希表存储走过的点的权值前缀和
class Solution {
public:

    void dfs(TreeNode* node, int targetSum, unordered_map<int, int>& mp, int sum, int& ans) {
        if (!node)
            return;
        sum += node->val;
        ans += mp[sum - targetSum];
        mp[sum] ++ ;
        dfs(node->left, targetSum, mp, sum, ans);
        dfs(node->right, targetSum, mp, sum, ans);
        mp[sum] -- ;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        dfs(root, targetSum, mp, 0, ans);
        return ans;
    }
};