/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> s(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ ) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        return dfs(1, 1, n, n, s);
    }

    Node* dfs(int x1, int y1, int x2, int y2, vector<vector<int>>& s) {
        int sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        int n = x2 - x1 + 1;
        if (sum == 0 || sum == n * n) {
            return new Node(!!sum, true);
        }
        else {
            auto node = new Node(0, false);
            node->topLeft = dfs(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, s);
            node->topRight = dfs(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2, s);
            node->bottomLeft = dfs((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2, s);
            node->bottomRight = dfs((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2, s);
            return node;
        }
    }
};
