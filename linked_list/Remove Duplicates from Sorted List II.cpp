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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* curr;
        curr = head;
        ListNode* prev = NULL;
        while (curr) {
            while (curr && curr->next && curr->val == curr->next->val) {
                int val = curr->val;
                while (curr && curr->val == val) {
                    curr = curr->next;
                }
            }
            if(!prev){
                head = curr;
            }else
            prev->next = curr;
            if (curr) {

                prev = curr;
                curr = prev->next;
            }
        }
        return head;
    }
};
