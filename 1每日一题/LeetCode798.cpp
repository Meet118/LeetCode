class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> b(n + 1);
        for (int i = 0; i < n; i ++ ) {
            int l = i - nums[i] + 1, r = i;
            if (l >= 0)
                b[l] += 1, b[r + 1] -= 1;
            else
                b[l + n] += 1, b[n] -= 1, b[0] += 1, b[r + 1] -= 1;
        }
        int maxk = 1e9, ans = 0;
        for (int i = 0, sum = 0; i < n; i ++ ) {
            sum += b[i];
            if (sum < maxk)
                maxk = sum, ans = i;
        }
        return ans;
    }
};
