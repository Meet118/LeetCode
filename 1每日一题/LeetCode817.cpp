/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> se(nums.begin(), nums.end());
        int ans = 0, cur = 0;
        while (head) {
            if (se.count(head->val)) {
                cur ++ ;
            }
            else {
                if (cur > 0)
                    ans ++ ;
                cur = 0;
            }
            head = head->next;
        }
        if (cur > 0) ans ++ ;
        return ans;
    }
};
