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
//递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        return searchBST(root->val > val ? root->left : root->right, val);
    }
};

//迭代
/*
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (true) {
            if (!root) 
                return NULL;
            if (root->val == val)
                return root;
            root = root->val > val ? root->left : root->right;
        }
    }
};
*/
