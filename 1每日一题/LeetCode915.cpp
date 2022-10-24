class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n), b(n);
        a[0] = nums[0], b[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i ++ )
            a[i] = max(nums[i], a[i - 1]);
        for (int i = n - 2; i >= 0; i -- )
            b[i] = min(nums[i], b[i + 1]);
        for (int i = 1; i < n; i ++ )
            if (a[i - 1] <= b[i])
                return i;
        return -1;
    }
};
