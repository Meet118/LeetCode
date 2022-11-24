typedef long long ll;
class Solution {
public:
    ll calc(vector<int> a, int x) {
        ll ans = 0;
        for (int i = 0; i < a.size(); i ++ ) {
            if (a[i] > x) continue;
            int j = i;
            while (j < a.size() && a[j] <= x) j ++ ;
            int k = j - i;
            i = j;
            ans += (ll)(k + 1) * k / 2;
        }
        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return calc(nums, right) - calc(nums, left - 1);
    }
};
