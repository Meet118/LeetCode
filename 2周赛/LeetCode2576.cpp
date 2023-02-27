class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n / 2;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid, nums)) l = mid;
            else r = mid - 1;
        }
        return l * 2;
    }

    bool check(int mid, vector<int>& a) {
        for (int i = 0, j = a.size() - mid; i < mid; i ++ , j ++ ) {
            if (a[i] * 2 > a[j])
                return false;
        }
        return true;
    }
};
