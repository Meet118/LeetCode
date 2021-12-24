class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        int ans = 0;
        int i = 0;
        while (true) {
            if (i < n)
                heap.push({i + days[i] - 1, apples[i]});
            while (heap.size() && (heap.top().first < i || heap.top().second <= 0))
                heap.pop();
            if (heap.size()) {
                auto t = heap.top();
                heap.pop();
                ans ++ ;
                heap.push({t.first, t.second - 1});
            }
            i ++ ;
            if (i >= n && heap.empty())
                break;
        }
        return ans;
    }
};
