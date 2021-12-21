class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        int ans = 0;
        vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
            month[2] ++ ;
        for (int i = 1; i < m; i ++ )
            ans += month[i];
        return ans + d;
    }
};
