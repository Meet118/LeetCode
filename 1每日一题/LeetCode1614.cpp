class Solution {
public:
    int maxDepth(string s) {
        int deep = 0, ans = 0;
        for (char c : s) {
            if (c == '(')
                deep ++ , ans = max(ans, deep);
            else if (c == ')')
                deep -- ;
        }
        return ans;
    }
};
