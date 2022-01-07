class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        while (n -- ) {
            int m = ans.size();
            for (int i = m - 1; i >= 0; i -- ) {
                ans[i] *= 2;
                ans.push_back(ans[i] + 1);
            }
        }
        return ans;
    }
};
