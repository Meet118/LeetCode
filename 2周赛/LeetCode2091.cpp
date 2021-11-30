class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a, b;
        int ma = -1e6, mi = 1e6;
        int n = nums.size();
        for (int i = 0; i < n; i ++ ) {
            if (nums[i] > ma) {
                a = i;
                ma = nums[i];
            }
            if (nums[i] < mi) {
                b = i;
                mi = nums[i];
            }
        }
        if (a > b)
            swap(a, b);
        int ans = b + 1;
        ans = min(ans, n - a);
        ans = min(ans, a + 1 + n - b);
        return ans;
    }
};

