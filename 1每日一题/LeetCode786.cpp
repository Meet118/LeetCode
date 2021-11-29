//二分找到大于等于k个数的最小数
//判断某个浮点数大于的数的个数用双指针计算
//找到目标值后再用双指针找到对应的分子分母
class Solution {
public:
    const double eps = 1e-8;

    int get(vector<int>& arr, double x) {
        int res = 0;
        for (int i = 0, j = 0; i < arr.size(); i ++ ) {
            while (j < i && (double)arr[j] / arr[i] <= x) j ++ ;
            if (j && (double)arr[j - 1] / arr[i] <= x) res += j;
        }
        return res;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, r = (double)arr[n - 1] / arr[0];
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (get(arr, mid) >= k) r = mid;
            else l = mid;
        }
        int a, b;
        for (int i = 0, j = 0; i < arr.size(); i ++ ) {
            while (j < i && (double)arr[j] / arr[i] <= r) j ++ ;
            if (j && fabs((double)arr[j - 1] / arr[i] - r) < eps) {
                a = arr[j - 1];
                b = arr[i];
            }
        }
        return {a, b};
    }
};
