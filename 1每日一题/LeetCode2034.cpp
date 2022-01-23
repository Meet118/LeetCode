class StockPrice {
public:
    int curtime;
    unordered_map<int, int> mp;
    priority_queue<int, vector<int>, less<int>> heap1; //大
    priority_queue<int, vector<int>, greater<int>> heap2; //小
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
        heap1.push(price);        
        heap2.push(price);
    }
    
    int current() {
        return mp[curtime];
    }
    
    int maximum() {
        while (cnt[heap1.top()] == 0)
            heap1.pop();
        return heap1.top();
    }
    
    int minimum() {
        while (cnt[heap2.top()] == 0)
            heap2.pop();
        return heap2.top();
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
