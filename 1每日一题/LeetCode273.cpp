class Solution {
public:
    unordered_map<int, string> mp {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };
    vector<string> s = {"Billion", "Million", "Thousand"};

    vector<string> change(int x) { //转换三位数
        int a = x / 100, b = x % 100;
        vector<string> res;
        if (a != 0) {
            res.push_back(mp[a]);
            res.push_back("Hundred");
        }
        if (b <= 20 && b > 0)
            res.push_back(mp[b]);
        else if (b > 20) {
            int c = b % 10;
            res.push_back(mp[b / 10 * 10]);
            if (c != 0)
                res.push_back(mp[c]);
        }
        return res;
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string ans = "";
        vector<string> a;

        for (int i = 3; i >= 0; i -- ) {
            int n = pow(1000, i);
            int m = num / n % 1000;
            if (m == 0)
                continue;
            vector<string> b;
            b = change(m);
            a.insert(a.end(), b.begin(), b.end());
            if (i)
                a.push_back(s[3 - i]);
        }
        for (auto i : a)
            ans += i + " ";
        ans.pop_back();
        return ans;
    }
};