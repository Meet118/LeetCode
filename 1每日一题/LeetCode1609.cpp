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
    unordered_map<int, vector<int>> mp;

    void dfs(TreeNode* u, int d) {
        if (!u) return;
        mp[d].push_back(u->val);
        dfs(u->left, d + 1);
        dfs(u->right, d + 1);
    }

    bool isEvenOddTree(TreeNode* root) {
        dfs(root, 0);
        for (auto& [k, v] : mp) {
            int n = v.size();
            for (int i = 0; i < n; i ++ ) {
                if ((k % 2 != 0 && v[i] % 2 != 0) || (k % 2 == 0 && v[i] % 2 == 0))
                    return false;
                if (i && ((k % 2 != 0 && v[i] >= v[i - 1]) || (k % 2 == 0 && v[i] <= v[i - 1])))
                    return false;
            }
        }
        return true;
    }
};
