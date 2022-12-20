class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(nums, maxOperations, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool check(vector<int>& nums, int m, int x) {
        int res = 0;
        for (int i : nums) {
            res += (i - 1) / x;
            if (res > m) return false;
        }
        return res <= m;
    }
};
