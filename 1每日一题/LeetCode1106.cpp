class Solution {
public:
    stack<char> stk;
    stack<char> op;

    int change(char c) {
        return c == 't' ? 1 : 0;
    }

    void eval() {
        auto opt = op.top();
        op.pop();
        int num = change(stk.top());
        stk.pop();
        if (opt == '!')
            num = !num;
        while (stk.top() != '(') {
            int n = change(stk.top());
            stk.pop();
            if (opt == '&')
                num &= n;
            else if (opt == '|')
                num |= n;
        }
        if (stk.top() == '(')
            stk.pop();
        stk.push(num == 1 ? 't' : 'f');
    }

    bool parseBoolExpr(string expression) {
        for (auto c : expression) {
            if (c == '!' || c == '&' || c == '|') {
                op.push(c);
            } else if (c == '(') {
                stk.push(c);
            } else if (c == ')') {
                eval();
            } else if (c == 'f' || c == 't') {
                stk.push(c);
            }
        }
        return stk.top() == 't';
    }
};
