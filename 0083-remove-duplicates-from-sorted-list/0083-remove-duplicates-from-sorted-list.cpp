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
        if(head == nullptr) {
            return head;
        }
        if(head->next == nullptr) {
            return head;
        }
        ListNode* ptr1;
        ListNode* ptr2;
        ptr1 = head;
        ptr2 = head->next;
        while(ptr2 != nullptr) {
            if(ptr1->val == ptr2->val) {
                ptr1->next = ptr2->next;
                ptr2 = ptr1->next;
                continue;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return head;
    }
};