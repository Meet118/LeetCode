class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; //low和high表示左括号的范围
        for (auto i : s) {
            if (i == '(')
                low ++ , high ++ ;
            else if (i == ')')
                low -- , high -- ;
            else if (i == '*')
                low -- , high ++ ;
            low = max(low, 0);
            if (low > high) return false;
        }
        return low == 0;
    }
};