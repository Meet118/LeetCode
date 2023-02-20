class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> q;
        for (int x : gifts)
            q.push(x);
        while (k -- ) {
            auto t = q.top();
            q.pop();
            q.push(sqrt(t));
        }
        long long ans = 0;
        while (q.size()) {
            auto t = q.top();
            q.pop();
            ans += t;
        }
        return ans;
    }
};

