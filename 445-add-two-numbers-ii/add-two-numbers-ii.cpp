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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;

        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        int c = 0;
        while (!st1.empty() || !st2.empty() || c > 0) {
            int a = 0, b = 0;
            if (!st1.empty()) {
                a = st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                b = st2.top();
                st2.pop();
            }
            int x = a + b + c;
            int dig = x % 10;
            c = x / 10;
            ListNode* node = new ListNode(dig);
            node->next=head;
            head=node;
        }
        return head;
    }
};