class Solution {
public:
    int getLucky(string s, int k) {
        string a;
        for (auto c : s) a += to_string(c - 'a' + 1);
        int sum = 0;            
        for (int i = 0; i < k; i ++ ) {
            sum = 0;
            for (auto c : a) sum += c - '0';
            a = to_string(sum);
        }
        return sum;
    }
};
