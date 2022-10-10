class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> f(n, vector<int>(2, 0x3f3f3f3f));
        f[0][0] = 0;
        f[0][1] = 1;
        for (int i = 1; i < n; i ++ ) {
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
                f[i][0] = f[i - 1][0];
                f[i][1] = f[i - 1][1] + 1;
            }
            if (nums2[i - 1] < nums1[i] && nums1[i - 1] < nums2[i]) {
                f[i][0] = min(f[i][0], f[i - 1][1]);
                f[i][1] = min(f[i][1], f[i - 1][0] + 1);
            }
        }
        return min(f[n - 1][0], f[n - 1][1]);
    }
};
