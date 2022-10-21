class StockSpanner {
public:
    stack<int> day, p;
    int k = 0;

    StockSpanner() {
        day.push(-1);
        p.push(1e6);
    }
    
    int next(int price) {
        while (price >= p.top()) {
            p.pop();
            day.pop();
        }
        int ans = k - day.top();
        day.push(k);
        p.push(price);
        k ++ ;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
