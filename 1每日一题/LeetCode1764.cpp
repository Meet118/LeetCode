class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int k = 0;
        for (auto g : groups) {
            int la = k;
            for (int i = 0; i < g.size(); i ++ ) {
                if (k >= nums.size()) return false;
                if (nums[k] == g[i]) {
                    k ++ ;
                } else {
                    i = -1;
                    la ++ ;
                    k = la;
                }
            }
        }
        return true;
    }
};
