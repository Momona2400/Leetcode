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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr) {
            return list2;
        }
        else if(list2 == nullptr) {
            return list1;
        }

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* start;
        // ListNode* ptr3 = list2->next;
        if(ptr1->val < ptr2->val) {
            start = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            start = ptr2;
            ptr2 = ptr2->next;
        }
        ListNode* ptr = start;
        while(ptr1 != nullptr && ptr2 != nullptr) {
            // while(ptr2->val > ptr1->val) {
            //     ptr1 = ptr1->next;
            // }
            if(ptr1->val < ptr2->val) {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        if(ptr1 != nullptr) {
            ptr->next = ptr1;
        }
        if(ptr2 != nullptr) {
            ptr->next = ptr2;
        }
        return start;
    }
};