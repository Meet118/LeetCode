class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int op = 0, l = boxes[0] == '1', r = 0;
        for (int i = 1; i < n; i ++ ) {
            if (boxes[i] == '1') {
                r ++ ;
                op += i;
            }
        }
        vector<int> ans(n);
        ans[0] = op;
        for (int i = 1; i < n; i ++ ) {
            op += l - r;
            if (boxes[i] == '1') {
                l ++ ;
                r -- ;
            }
            ans[i] = op;
        }
        return ans;
    }
};
