typedef long long ll;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        ll sum = 0;
        for (int x : nums) sum += x;
        ll s = abs(sum - goal);
        return (s + limit - 1) / limit;
    }
};
