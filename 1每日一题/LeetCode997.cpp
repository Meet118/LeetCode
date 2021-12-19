class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> a(n + 1), b(n + 1);
        for (auto i : trust) {
            a[i[0]] ++ ;
            b[i[1]] ++ ;
        }
        int ans = -1;
        for (int i = 1; i <= n; i ++ )
            if (a[i] == 0 && b[i] == n - 1)
                ans = i;
        return ans;
    }
};
