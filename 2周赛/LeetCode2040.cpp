class Solution {
public:
    long long er(long long x, vector<int>& a, vector<int>& b) { //返回小于等于x的积的个数
        long long cnt = 0;
        for (long long n : a) {
            if (n > 0) {
                if (n * b[0] > x) continue;
                int l = 0, r = b.size() - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (n * b[mid] <= x) l = mid;
                    else r = mid - 1;
                }
                cnt += l + 1;
            }
            else if (n < 0) {
                if (n * b.back() > x) continue;
                int l = 0, r = b.size() - 1;
                while (l < r) {
                    int mid = l + r >> 1;
                    if (n * b[mid] <= x) r = mid;
                    else l = mid + 1;
                }
                cnt += b.size() - l;
            }
            else if (n == 0 && x >= 0) cnt += b.size();
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e11, r = 1e11;
        while (l < r) {
            long long mid = l + r + 1 >> 1;
            //如果小于mid的数的个数小于k
            if (er(mid, nums1, nums2) < k) l = mid;
            else r = mid - 1;
        }
        //返回下一个数
        return l + 1;
    }
};
