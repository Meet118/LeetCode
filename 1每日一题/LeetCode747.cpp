class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = 0;
        for (int i = 1; i < nums.size(); i ++ )
            if (nums[i] > nums[idx])
                idx = i;
        for (int x : nums)
            if (x != nums[idx] && x * 2 > nums[idx])
                return -1;
        return idx;
    }
};
