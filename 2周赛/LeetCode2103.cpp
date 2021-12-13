class Solution {
public:
    int countPoints(string rings) {
        vector<int> state(10);
        unordered_map<char, int> mp = {{'R', 1}, {'G', 2}, {'B', 4}};
        for (int i = 0; i < rings.size(); i += 2) {
            state[rings[i + 1] - '0'] |= mp[rings[i]];
        }
        int ans = 0;
        for (int i = 0; i < 10; i ++ )
            if (state[i] == 7)
                ans ++ ;
        return ans;
    }
};

