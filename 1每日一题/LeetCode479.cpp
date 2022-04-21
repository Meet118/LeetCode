class Solution {
public:
    int largestPalindrome(int n) {
        typedef long long ll;
        if (n == 1) return 9;
        ll maxv = pow(10, n) - 1;
        for (ll i = maxv; ; i -- ) {
            auto a = to_string(i);
            auto b = a;
            reverse(b.begin(), b.end());
            auto num = stoll(a + b);
            for (ll j = maxv; j * j >= num; j -- )
                if (num % j == 0)
                    return num % 1337;
        }
        return 0;
    }
};
