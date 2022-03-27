class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        vector<int> ans;
        for (int i : rolls)
            sum -= i;
        if (sum < n || sum > n * 6)
            return ans;
        sum -= n;
        for (int i = 0; i < n; i ++ ) {
            if (sum == 0)
                ans.push_back(1);
            else {
                ans.push_back(min(sum, 5) + 1);
                if (sum >= 5)
                    sum -= 5;
                else
                sum = 0;
            }
        }
        return ans;
    }
};
