class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for (int& x : hand)
            mp[x] ++ ;
        for (auto& [k, v] : mp) {
            while (mp[k] > 0)
                for (int i = k; i < k + groupSize; i ++ ) {
                    mp[i] -- ;
                    if (mp[i] < 0)
                        return false;
                }
        }
        for (auto& [k, v] : mp) {
            if (mp[k] > 0)
                return false;
        }
        return true;
    }
};
