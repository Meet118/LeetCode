class FreqStack {
public:
    unordered_map<int, stack<int>> stk;
    unordered_map<int, int> c;
    int n;

    FreqStack() {

    }
    
    void push(int val) {
        c[val] ++ ;
        stk[c[val]].push(val);
        n = max(n, c[val]);
    }
    
    int pop() {
        int ans = stk[n].top();
        stk[n].pop();
        c[ans] -- ;
        if (stk[n].size() == 0) n -- ;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
