class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i ++ ) {
            int j = i;
            int sum = nums[i];
            while (j + 1 < nums.size() && nums[j] < nums[j + 1]) j ++ , sum += nums[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};
