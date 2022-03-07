class Solution {
public:
    string convertToBase7(int num) {
        string s = "";
        bool f = false;
        if (num < 0)
            f = true;
        num = abs(num);
        while (num || s.size() == 0) {
            s = to_string(num % 7) + s;
            num /= 7;
        }
        if (f)
            s = '-' + s;
        return s;
    }
};
