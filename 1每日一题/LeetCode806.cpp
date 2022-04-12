class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1, cur = 0;
        for (char c : s) {
            int t = c - 'a';
            if (cur + widths[t] > 100) {
                cur = widths[t];
                line ++ ;
            }
            else
                cur += widths[t];
        }
        return {line, cur};
    }
};
