//n²
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        int ans = 0;
        for (int i = 0; i < n; i ++ ) {
            f[i] = 1;
            for (int j = 0; j < i; j ++ )
                if (nums[j] < nums[i])
                    f[i] = max(f[i], f[j] + 1);
            ans = max(f[i], ans);
        }
        return ans;
    }
};

//nlogn
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        for (auto x : nums) {
            if (a.size() == 0 || x > a.back()) a.push_back(x);
            else {
                if (x <= a[0]) a[0] = x;
                else {
                    int l = 0, r = a.size() - 1;
                    while (l < r) {
                        int mid = l + r + 1 >> 1;
                        if (a[mid] < x) l = mid;
                        else r = mid - 1;
                    }
                    a[l + 1] = x;
                }
            }
        }
        return a.size();
    }
};