class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[mid + 1]) l = mid + 1; //峰值一定出现在较大的半边
            else r = mid;
        }
        return l;
    }
};