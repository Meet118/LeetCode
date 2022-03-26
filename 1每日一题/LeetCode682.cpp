class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        for (auto s : ops) {
            int n = stk.size();
            if (s == "+") stk.push_back(stk[n - 1] + stk[n - 2]);
            else if (s == "D") stk.push_back(stk[n - 1] * 2);
            else if (s == "C") stk.pop_back();
            else stk.push_back(stoi(s));
        }
        int ans = 0;
        for (int i : stk) ans += i;
        return ans;
    }
};
