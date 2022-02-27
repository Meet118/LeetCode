class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = "";
        for (int i = 0; i < nums.size(); i ++ ) {
            ans += to_string(nums[i]);
            if (i + 1 < nums.size())
                ans += '/';
            if (nums.size() > 2 && i == 0)
                ans += '(';
            if (nums.size() > 2 && i + 1 == nums.size())
                ans += ')';
        }
        return ans;
    }
};
