class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> q;
        int n = score.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i ++ ) {
            q.push({score[i], i});
        }
        int rank = 1;
        vector<string> s = {
            "Gold Medal",
            "Silver Medal",
            "Bronze Medal"
        };

        while (q.size()) {
            auto i = q.top().second;
            q.pop();
            if (rank <= 3)
                ans[i] = s[rank - 1];
            else
                ans[i] = to_string(rank);
            rank ++ ;
        }
        return ans;
    }
};
