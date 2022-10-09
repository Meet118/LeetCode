class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        for (char c : s) {
            if (c == ')') {
                int t = stk.top();
                stk.pop();
                if (t == 0) t = 1;
                else t *= 2;
                stk.top() += t;
            }
            else
                stk.push(0);
        }
        return stk.top();
    }
};
