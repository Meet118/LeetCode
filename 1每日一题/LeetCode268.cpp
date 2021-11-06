//标记数组
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++ ) {
            int x = nums[i];
            if (x < 0) {
                int t = -x - 1;
                if (t >= 0 && t < n)
                    nums[t] = -nums[t] - 1;
            }
            else if (x < n) {
                nums[x] = -nums[x] - 1;
            }
        }
        for (int i = 0; i < n; i ++ )
            if (nums[i] >= 0)
                return i;
        return n;
    }
};

//数学
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n * (n + 1) / 2;
        for (int x : nums) res -= x;
        return res;
    }
};

//位运算
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i ++ ) res ^= nums[i] ^ i;
        return res ^ nums.size();
    }
};