class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        int st = 0;
        for (auto c : allowed) st |= (1 << (c - 'a'));
        for (auto s : words) {
            bool f = true;
            for (auto c : s) {
                if (((st >> (c - 'a')) & 1) == 0) {
                    f = false;
                    break;
                }
            }
            if (f) ans ++ ;
        }
        return ans;
    }
};
