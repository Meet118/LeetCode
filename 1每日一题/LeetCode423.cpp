class Solution {
public:
    vector<string> en = {
        "zero", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine"
    };

    bool minus(vector<int>& a, int x) {
        for (char c : en[x])
            if (a[c - 'a'] == 0)
                return false;
        for (char c : en[x]) {
            a[c - 'a'] -- ;
        }
        return true;
    }

    string originalDigits(string s) {
        vector<int> a(26);
        for (char c : s)
            a[c - 'a'] ++ ;
        vector<int> ord = {0, 6, 2, 8, 3, 4, 5, 7, 1, 9};
        string ans;
        for (int i = 0; i < 10; i ++ ) {
            while (minus(a, ord[i]))
                ans += to_string(ord[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
