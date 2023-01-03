class Solution {
public:
    typedef long long ll;

    struct Node {
        int cnt, price;
        bool operator < (const Node &a) const {
            return price < a.price;
        }
    };

    struct Node1 {
        int cnt, price;
        bool operator < (const Node1 &a) const {
            return price > a.price;
        }
    };

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<Node> buy;
        priority_queue<Node1> sell;
        for (auto order : orders) {
            if (order[2] == 0) { //buy
               while (order[1] > 0) {
                    if (sell.empty()) break;
                    auto t = sell.top();
                    if (t.price > order[0]) {
                        break;                        
                    }
                    sell.pop();
                    if (order[1] > t.cnt) {
                        order[1] -= t.cnt;
                    } else {
                        if (t.cnt - order[1] > 0)
                            sell.push({t.cnt - order[1], t.price});
                        order[1] = 0;
                        break;
                    }
                }
                if (order[1] > 0)
                    buy.push({order[1], order[0]});
            } else {
                while (order[1] > 0) {
                    if (buy.empty()) break;
                    auto t = buy.top();
                    if (t.price < order[0]) {
                        break;                        
                    }
                    buy.pop();
                    if (order[1] > t.cnt) {
                        order[1] -= t.cnt;
                    } else {
                        if (t.cnt - order[1] > 0)
                            buy.push({t.cnt - order[1], t.price});
                        order[1] = 0;
                        break;
                    }
                }
                if (order[1] > 0)
                    sell.push({order[1], order[0]});
            }
        }
        ll ans = 0;
        const int mod = 1e9 + 7;
        while (buy.size()) {
            auto t = buy.top();
            buy.pop();
            ans = (ans + t.cnt) % mod;
        }
        while (sell.size()) {
            auto t = sell.top();
            sell.pop();
            ans = (ans + t.cnt) % mod;
        }
        return ans;
    }
};
