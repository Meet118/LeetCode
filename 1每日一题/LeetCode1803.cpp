class Solution {
public:
    struct Node {
        Node* child[2];
        int cnt;
    };

    Node* root;
    int n;

    void add(int x) {
        Node* u = root;
        for (int i = n; i >= 0; i -- ) {
            int t = (x >> i & 1);
            if (u->child[t] == nullptr)
                u->child[t] = new Node();
            u = u->child[t];
            u->cnt ++ ;
        }
    }

    int calc(int maxv, int x) {
        Node* u = root;
        int res = 0;
        for (int i = n; i >= 0; i -- ) {
            int a = (maxv >> i & 1), b = (x >> i & 1);
            if (a == 0) {
                if (u->child[b] == nullptr) return res;
                u = u->child[b];
            }
            else {
                if (u->child[b] != nullptr)
                    res += u->child[b]->cnt;
                if (u->child[b ^ 1] == nullptr) return res;
                u = u->child[b ^ 1];
            }
        }
        return res + u->cnt;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        n = 15;
        root = new Node();
        int ans = 0;
        for (int x : nums) {
            ans += calc(high, x) - calc(low - 1, x);
            add(x);
        }
        return ans;
    }
};
