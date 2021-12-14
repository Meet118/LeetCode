class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        priority_queue<int> heap;
        int t = 0;
        for (int i = 0; i < n; i ++ ) {
            heap.push(courses[i][0]);
            t += courses[i][0];
            if (t > courses[i][1]) {
                t -= heap.top();
                heap.pop();
            }
        }
        return heap.size();
    }
};
