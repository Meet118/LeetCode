class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> mon = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = 0;
        days += (year - 1971) * 365 + (year - 1969) / 4;
        for (int i = 1; i < month; i ++ )
            days += mon[i];
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3)
            days += 1;
        days += day;
        return weeks[(days + 4) % 7];
    }
};
