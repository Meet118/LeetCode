class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> c1(26), c2(26);
        for (auto c : s) c1[c - 'a'] ++ ;
        for (auto c : target) c2[c - 'a'] ++ ;
        int ans = 1000;
        for (int i = 0; i < 26; i ++ ) {
            if (c1[i] > 0 && c2[i] > 0) {
                ans = min(ans, c1[i] / c2[i]);
            } else if (c1[i] == 0 && c2[i] > 0) {
                return 0;
            }
        }
        return ans;
    }
};
