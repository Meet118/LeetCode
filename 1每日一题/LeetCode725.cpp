//模拟创建链表
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        int n = 0;
        ListNode* a = head;
        while (a) {
            n ++ ;
            a = a->next;
        }

        a = head;
        for (int i = 0; i < k; i ++ ) {
            int per = n / k;
            if (i < n % k)
                per ++ ;
            ListNode* dummy = new ListNode();
            ListNode* res = dummy;
            for (int j = 0; j < per; j ++ ) {
                res->next = new ListNode(a->val);
                res = res->next;
                a = a->next;
            }
            ans.push_back(dummy->next);
        }
        return ans;
    }
};
//使用原链表创建
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        int n = 0;
        ListNode* a = head;
        while (a) {
            n ++ ;
            a = a->next;
        }

        a = head;
        for (int i = 0; i < k; i ++ ) {
            int per = n / k;
            if (i < n % k)
                per ++ ;
            ans.push_back(a);
            for (int j = 0; j < per - 1; j ++ )
                a = a->next;
            if (a) {
                auto t = a->next;
                a->next = nullptr;
                a = t; //指针重新赋值
            }
        }
        return ans;
    }
};