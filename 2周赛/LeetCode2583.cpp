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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t.first) {
                mp[t.second].push_back(t.first->val);
                q.push({t.first->left, t.second + 1});
                q.push({t.first->right, t.second + 1});
            }
        }
        vector<long long> a;
        for (auto [k, v] : mp) {
            long long res = 0;
            for (int x : v) res += x;
            a.push_back(res);
        }
        sort(a.begin(), a.end());
        if (a.size() < k) return -1;
        return a[a.size() - k];
    }
};

