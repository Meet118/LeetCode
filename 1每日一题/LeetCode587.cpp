class Solution {
public:
    int cross(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }

    int area(vector<int> a, vector<int> b, vector<int> c) {
        return cross(a[0] - b[0], a[1] - b[1], a[0] - c[0], a[1] - c[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        sort(trees.begin(), trees.end());
        vector<int> hull(n + 2);
        vector<int> used(n);
        int top = 0;
        for (int i = 0; i < n; i ++ ) {
            while (top >= 2 && area(trees[hull[top - 1]], trees[hull[top]], trees[i]) > 0)
                used[hull[top -- ]] = 0;
            used[i] = 1;
            hull[ ++ top] = i;
        }
        used[0] = 0;
        for (int i = n - 1; i >= 0; i -- ) {
            if (used[i]) continue;
            while (top >= 2 && area(trees[hull[top - 1]], trees[hull[top]], trees[i]) > 0)
                used[hull[top -- ]] = 0;
            used[i] = 1;
            hull[ ++ top] = i;           
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= top; i ++ )
            ans.push_back(trees[hull[i]]);
        ans.pop_back();
        return ans;
    }
};
