class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int cur = 1;
        for (int i = 0, j = 0; i < n; i ++ ) {
            cur *= nums[i];
            while (j <= i && cur >= k) {
                cur /= nums[j];
                j ++ ;
            }
            ans += (i - j + 1);
        }  
        return ans;
    }
};
