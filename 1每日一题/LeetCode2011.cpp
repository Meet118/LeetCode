class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string s : operations) {
            if (s[1] == '-') ans -- ;
            else ans ++ ;
        }
        return ans;
    }
};
