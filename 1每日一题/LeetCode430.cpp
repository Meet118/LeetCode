/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
//用栈存储有子项节点的后半段
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> stk;

        Node* p = head;
        Node* res = p;

        while (p) {
            if (p->child) {
                if (p->next)
                    stk.push(p->next);
                p = p->child;
                res->next = p;
                p->prev = res;
                res->child = nullptr;
                res = p;
            }
            else if (!p->next) {
                if (stk.size()) {
                    p = stk.top();
                    stk.pop();
                    res->next = p;
                    p->prev = res;
                    res = p;
                }
                else break;
            }
            else {
                p = p->next;
                res = p;
            }
        }

        return head;
    }
};