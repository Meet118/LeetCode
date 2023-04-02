class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, map<int, int>> group; //分成同余的组
        for (auto x : nums)
            group[x % k][x] ++ ;
        int ans = 1;
        for (auto [_, g] : group) {
            int n = g.size();
            vector<int> f(n + 1);
            auto it = g.begin();
            f[0] = 1;
            f[1] = (1 << it->second);
            int la = it->first;
            it ++ ;
            for (int i = 2; i <= n; it ++ , i ++ ) {
                f[i] = f[i - 1]; //不选当前数
                if (it->first - la == k) //选当前数
                    f[i] += f[i - 2] * ((1 << it->second) - 1);
                else 
                    f[i] += f[i - 1] * ((1 << it->second) - 1);
                la = it->first;
            }
            ans *= f[n]; //每个组的数量
        }
        return ans - 1; //减去空集
    }
};

