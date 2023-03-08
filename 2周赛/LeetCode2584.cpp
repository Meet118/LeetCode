class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int> all; //每个质因子的数量
        unordered_map<int, vector<int>> yz; //每个数的质因子
        for (int x : nums) {
            int t = x;
            bool f = true;
            if (yz.count(x)) f = false;
            for (int i = 2; i <= t / i; i ++ ) {
                while (t % i == 0) {
                    if (f)
                        yz[x].push_back(i);
                    t /= i;
                    all[i] ++ ;
                }
            }
            if (t > 1) {
                if (f)
                    yz[x].push_back(t);
                all[t] ++ ;
            }
        }
        unordered_map<int, int> cur; //当前各质因子数量
        unordered_set<int> dif; //质因子数量不相等的集合
        for (int i = 0; i + 1 < nums.size(); i ++ ) {
            unordered_set<int> se; //当前数的因子
            for (int x : yz[nums[i]]) {
                cur[x] ++ ;
                se.insert(x);
            }
            for (auto x : se) {
                if (cur[x] != all[x]) dif.insert(x);
                else dif.erase(x);
            }
            if (dif.size() == 0)
                return i;
        }
        return -1;
    }
};

