class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> mp;
        for (auto i : ages)
            mp[i] ++ ;
        int ans = 0;
        for (int i = 1; i <= 120; i ++ ) {
            if (mp[i] > 0)
                for (int j = 1; j <= 120; j ++ )
                    if (mp[j] > 0 && check(i, j)) {
                        ans += mp[j] * mp[i];
                        if (j == i)
                            ans -= mp[i];
                    }
        }
        return ans;
    }

    bool check(int x, int y) {
        if (y <= 0.5 * x + 7) return false;
        if (y > x) return false;
        if (y > 100 && x < 100) return false;
        return true;
    }
};
