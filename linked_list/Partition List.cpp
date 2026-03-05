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
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0);
        ListNode node2(0);
        ListNode* curr1 = &node1;
        ListNode* curr2 = &node2;

        while (head != NULL) {
            if (head->val < x) {
                curr1->next = head;
                curr1 = curr1->next;
            } else {
                curr2->next = head;
                curr2 = curr2->next;
            }
            head = head->next;
        }

        curr2->next = nullptr;
        curr1->next = node2.next;
        return node1.next;
    }
};
