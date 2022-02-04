class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxlen = 0, ans = 0;
        for (auto i : rectangles) {
            int t = min(i[0], i[1]);
            if (t == maxlen) {
                ans ++ ;
            }
            else if (t > maxlen) {
                ans = 1;
                maxlen = t;
            }
        }
        return ans;
    }
};
