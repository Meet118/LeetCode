class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int ans = 0, sum = 0;
        for (auto& x : boxTypes) {
            if (sum + x[0] <= truckSize) {
                ans += x[0] * x[1];
                sum += x[0];
            } else {
                ans += (truckSize - sum) * x[1];
                break;
            }
        }
        return ans;
    }
};
