class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        work(nums, n);
        return nums[0];
    }

    void work(vector<int>& a, int n) {
        if (n == 1) return;
        int k = 0;
        for (int i = 0; i < n; i += 2) {
            if (k % 2 == 0)
                a[k ++ ] = min(a[i], a[i + 1]);
            else
                a[k ++ ] = max(a[i], a[i + 1]);
        }
        work(a, k);
    }
};
