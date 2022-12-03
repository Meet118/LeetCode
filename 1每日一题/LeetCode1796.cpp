class Solution {
public:
    int secondHighest(string s) {
        int cnt = 0, a = -1, b = -1;
        for (auto c : s) {
            if (isdigit(c)) {
                int x = c - '0';
                if (x > a) {
                    b = a;
                    a = x;
                } else if (x > b && x != a) {
                    b = x;
                }
            }
        }
        return b;
    }
};
