class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<int> b;
        for (int i = 0; i < n; i ++ ) {
            if (nums[i] == key)
                b.push_back(i);
        }
        for (int i = 0; i < n; i ++ ) {
            int t = lower_bound(b.begin(), b.end(), i) - b.begin();
            int res = 1e9;
            if (t < b.size())
                res = b[t] - i;
            if (t > 0)
                res = min(res, i - b[t - 1]);
            if (res <= k)
                ans.push_back(i);
        }
        return ans;
    }
};
