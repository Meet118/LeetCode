class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end());
        for (auto i : arr)
            mp[i] ++ ;
        for (int x : arr) {
            if (mp[x] == 0) continue;
            if (x < 0) {
                if (x % 2 || mp[x / 2] < mp[x])
                    return false;
                mp[x / 2] -= mp[x];
            }
            else if (x > 0) {
                if (mp[x * 2] < mp[x])
                    return false;
                mp[x * 2] -= mp[x];
            }
            mp[x] = 0;
        }

        return true;
    }
};
