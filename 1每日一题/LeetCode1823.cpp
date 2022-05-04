class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = f(n, k) + 1;
        return ans;
    }

    int f(int n, int k) {
        if (n < 1) return 0;
        int ans = (f(n - 1, k) + k) % n;
        return ans;
    }
};
