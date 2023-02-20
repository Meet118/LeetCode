class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (i != j) {
                string s = to_string(nums[i]) + to_string(nums[j]);
                ans += stoll(s);
            } else {
                string s = to_string(nums[i]);
                ans += stoll(s);
                break;
            }
            i ++ , j -- ;
        }
        return ans;
    }
};

