/*
类似单调栈思想 找到左边和右边第一个比本身大和小的数 若不存在 则本身满足左边均小于和右边均大于 满足美丽值2的条件
美丽值1的条件扫描一遍即可判断
*/
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n);
        vector<int> r(n);
        
        int maxn = nums[0];
        for (int i = 1; i < n; i ++ ) {
            if (nums[i] > maxn)
                l[i] = 1;
            maxn = max(maxn, nums[i]);
        }

        int minn = nums[n - 1];
        for (int i = n - 2; i >= 0; i -- ) {
            if (nums[i] < minn)
                r[i] = 1;
            minn = min(minn, nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i ++ ) {
            if (l[i] && r[i])
                ans += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                ans ++ ;
        }
        return ans;
    }
};