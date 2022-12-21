class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int d[] = {a, b, c};
        sort(d, d + 3);
        int x = 0;
        if (d[0] + d[1] < d[2]) x = d[2] - (d[1] + d[0]);
        else x = (d[0] + d[1] + d[2]) % 2;
        return (a + b + c - x) / 2;
    }
};
