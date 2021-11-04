class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while (l < r) {
            int mid = l + r >> 1;
            if (mid && mid >= num / mid) r = mid;
            else l = mid + 1;
        }
        return (long long)l * l == num;
    }
};