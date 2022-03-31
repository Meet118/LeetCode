class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; num ++ ) {
            int x = num;
            bool f = true;
            while (x) {
                int t = x % 10;
                if (t == 0 || num % t != 0) {
                    f = false;
                    break;
                }
                x /= 10;
            }
            if (f)
                ans.push_back(num);
        }
        return ans;
    }
};
