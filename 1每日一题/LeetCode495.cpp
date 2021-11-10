class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        for (int i = 0; i < timeSeries.size(); i ++ ) {
            if (i + 1 < timeSeries.size() && timeSeries[i + 1] - timeSeries[i] < duration)
                ans += timeSeries[i + 1] - timeSeries[i];
            else
                ans += duration;
        }
        return ans;
    }
};