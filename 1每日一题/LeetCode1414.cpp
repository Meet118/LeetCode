class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> a = {1, 1};
        int i = 2;
        while (a[i - 2] <= k - a[i - 1]) {
            a.push_back(a[i - 2] + a[i - 1]);
            i ++ ;
        }
        int n = a.size() - 1;
        int ans = 0;
        while (k && n >= 0) {
            while (k - a[n] >= 0) {
                k -= a[n];
                ans ++ ;
            }
            n -- ;
        }
        return ans;
    }
};
