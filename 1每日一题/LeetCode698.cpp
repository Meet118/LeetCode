class Solution {
public:
    int n;
    vector<int> nums;

    bool canPartitionKSubsets(vector<int>& _nums, int k) {
        nums = _nums;
        sort(nums.begin(), nums.end(), greater<int>());
        n = nums.size();
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % k != 0)
            return false;

        return dfs(0, 0, sum / k, 0);
    }

    bool dfs(int start, int cur, int sum, int state) {
        if (cur == sum) {
            if (state == (1 << n) - 1)
                return true;
            return dfs(0, 0, sum, state);
        }
        for (int i = start; i < n; i ++ ) {
            if ((state >> i) & 1) continue;
            if (cur + nums[i] <= sum) {
                if (dfs(i + 1, cur + nums[i], sum, state | (1 << i)))
                    return true;
                if (!i || i + 1 == n) return false;
                while (i + 1 < n && nums[i] == nums[i + 1]) i ++ ;
            }
        }
        return false;
    }
};
