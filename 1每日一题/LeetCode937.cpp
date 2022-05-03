class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b) {
            auto i = a.find(' '), j = b.find(' ');
            auto a1 = a.substr(0, i), b1 = b.substr(0, j);
            auto a2 = a.substr(i + 1), b2 = b.substr(j + 1);
            bool fa = isdigit(a2[0]), fb = isdigit(b2[0]);
            cout << a << ' ' << b << endl;
            if (fa && fb) return false; //保留原顺序
            if (fa || fb) return fb; //字母在前
            else {
                if (a2 == b2) return a1 < b1; //内容相同
                return a2 < b2;
            }
        });
        return logs;
    }
};
