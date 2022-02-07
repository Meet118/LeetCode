class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int, char>> heap;
        heap.push({a, 'a'});
        heap.push({b, 'b'});
        heap.push({c, 'c'});
        int k = 0;
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            if (t.first == 0) continue;
            if (k >= 2 && s[k - 2] == s[k - 1] && s[k - 1] == t.second) { //不能放数量最多的字母
                auto t1 = heap.top();
                heap.pop();
                if (t1.first == 0) continue;
                s += t1.second;
                k ++ ;
                heap.push({t1.first - 1, t1.second});
                heap.push({t.first, t.second});
            }
            else { //可以放
                s += t.second;
                k ++ ;
                heap.push({t.first - 1, t.second});
            }
        }
        return s;
    }
};
