class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) return minOperations(nums2, nums1);
        if (n * 6 < m) return -1;
        int ans = 1e9;
        int a = 0, b = 0;
        vector<int> ca(7), cb(7);
        for (int x : nums1) a += x, ca[x] ++ ;
        for (int x : nums2) b += x, cb[x] ++ ;

        for (int i = m; i <= 6 * n; i ++ ) {
            ans = min(ans, get(a, i, ca) + get(b, i, cb));
        }
        return ans;
    }

    int get(int sum, int k, vector<int>& c) {
        int res = 0;
        if (sum > k) {
            for (int i = 6; i >= 2; i -- ) {
                int t = i - 1;
                if (t * c[i] >= sum - k) return res + (sum - k + t - 1) / t;
                res += c[i];
                sum -= c[i] * t;
            }
        }
        else if (sum < k) {
            for (int i = 1; i <= 5; i ++ ) {
                int t = 6 - i;
                if (t * c[i] >= k - sum) return res + (k - sum + t - 1) / t;
                res += c[i];
                sum += c[i] * t;
            }
        }
        return res;
    }
};
