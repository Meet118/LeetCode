#define pi 3.14159

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> a;
        int same = 0;
        for (auto i : points) {
            if (i[0] == location[0] && i[1] == location[1])
                same ++ ;
            else
                a.push_back(atan2(i[0] - location[0], i[1] - location[1]) * 180.0 / M_PI + 180);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int n = a.size();
        for (int i = 0; i < n; i ++ )
            a.push_back(a[i] + 360);
        priority_queue<double, vector<double>, greater<double>> heap;
        for (double x : a) {
            heap.push(x);
            while (x - heap.top() > angle)
                heap.pop();
            ans = max(ans, (int)heap.size());
        }
        return ans + same;
    }
};
