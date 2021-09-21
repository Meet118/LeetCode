//模拟一遍即可
class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int ans = 0;
        for (auto i : op) {
            if (i.find('+') != -1)
                ans ++ ;
            else
                ans -- ;
        }
        return ans;
    }
};