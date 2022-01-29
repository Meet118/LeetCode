class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](const auto & a, const auto & b){
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });

        stack<int> stk;
        int ans = 0;
        for (auto i : properties) {
            while (stk.size() && stk.top() <= i[1])
                stk.pop();
            if (i[0] != properties[0][0] && stk.size())
                ans ++ ;
            stk.push(i[1]);
        }
        return ans;
    }
};
