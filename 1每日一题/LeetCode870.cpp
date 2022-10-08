class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<int> id;
        int n = nums1.size();
        for (int i = 0; i < n; i ++ ) id.push_back(i);
        sort(id.begin(), id.end(), [&](int a, int b) {
            return nums2[a] < nums2[b];
        });
        vector<int> ans(n);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i ++ ) {
            if (nums1[i] > nums2[id[l]]) ans[id[l ++ ]] = nums1[i];
            else ans[id[r -- ]] = nums1[i];
        }
        return ans;
    }
};
