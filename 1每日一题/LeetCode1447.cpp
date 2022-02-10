class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j < i; j ++ ) {
                if (gcd(i, j) == 1) {
                    ans.push_back(to_string(j) + '/' + to_string(i));
                }
            }
        return ans;
    }
};
