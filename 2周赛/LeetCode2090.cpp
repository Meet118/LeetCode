class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < min(k, n); i ++ )
            sum += nums[i];
        for (int i = 0; i < n; i ++ ) {
            if (i + k < n)
                sum += nums[i + k];
            if (i - k - 1 >= 0)
                sum -= nums[i - k - 1];
            if (i < k || i + k >= n)
                ans.push_back(-1);
            else 
                ans.push_back(sum / (k * 2 + 1));
        }
        return ans;
    }
};

