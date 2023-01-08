class DataStream {
public:
    int v, k, c;
    
    DataStream(int value, int _k) {
        v = value;
        k = _k;
        c = 0;
    }
    
    bool consec(int num) {
        if (num == v) c ++ ;
        else c = 0;
        return c >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

