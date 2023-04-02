class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return a > b;
        });
        long long sum = 0;
        int ans = 0;
        for (int x : nums) {
            sum += x;
            if (sum > 0) ans ++ ;
        }
        return ans;
    }
};

