class StockPrice {
public:
    int curtime;
    unordered_map<int, int> mp;
    priority_queue<int, vector<int>, less<int>> q1; //大根堆
    priority_queue<int, vector<int>, greater<int>> q2; //小根堆
    unordered_map<int, int> cnt;
    
    StockPrice() {
        curtime = 0;
    }
    
    void update(int timestamp, int price) {
        curtime = max(curtime, timestamp);
        if (mp.count(timestamp)) {
            cnt[mp[timestamp]] -- ;
        }
        mp[timestamp] = price;
        cnt[price] ++ ;
        q1.push(price);        
        q2.push(price);
    }
    
    int current() {
        return mp[curtime];
    }
    
    int maximum() {
        while (cnt[q1.top()] == 0)
            q1.pop();
        return q1.top();
    }
    
    int minimum() {
        while (cnt[q2.top()] == 0)
            q2.pop();
        return q2.top();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */