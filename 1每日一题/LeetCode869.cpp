//统计数位
class Solution {
public:
    unordered_set<string> se;

    string countNum(int x) {
        string res = string(10, '0');
        while (x) {
            res[x % 10] ++ ;
            x /= 10;
        }
        return res;
    }

    bool reorderedPowerOf2(int n) {
        for (int i = 1; i <= 1e9; i *= 2)
            se.insert(countNum(i));
        return se.count(countNum(n));
    }
};