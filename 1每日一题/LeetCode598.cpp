class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m, b = n;
        for (auto& i : ops) {
            a = min(a, i[0]);
            b = min(b, i[1]);
        }
        return a * b;
    }
};