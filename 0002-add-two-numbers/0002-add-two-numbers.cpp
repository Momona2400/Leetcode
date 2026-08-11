// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//         ListNode *ptr1, *ptr2;
//         ptr1 = l1;
//         ptr2 = l2;
//         unsigned long long sum1 = 0, sum2 = 0, x, y = 1;
//         while(ptr1 != nullptr) {
//             x = ptr1->val;
//             sum1 += y*x;
//             y*=10;
//             ptr1 = ptr1->next;
//         }
//         y = 1;
//         while(ptr2 != nullptr) {
//             x = ptr2->val;
//             sum2 += y*x;
//             y*=10;
//             ptr2 = ptr2->next;
//         }

//         unsigned long long sum = sum1+sum2;

//         ListNode *l = new ListNode();
//         ListNode *ptr;
//         ptr = l;
//         int q = sum%10;
//         sum/=10;
//         ptr->val = q;
//         while(sum!=0) {
//             ptr->next = new ListNode();
//             ptr = ptr->next;
//             int q = sum%10;
//             sum/=10;
//             ptr->val = q;
//         }
//         ptr->next = nullptr;

//         return l;
        
//     }
// };





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
        ListNode *l = new ListNode();
        ListNode *ptr1, *ptr2, *ptr;
        int x, y, sum, c = 0;
        ptr1 = l1;
        ptr2 = l2;
        ptr = l;
        x = ptr1->val;
        ptr1 = ptr1->next;
        y = ptr2->val;
        ptr2 = ptr2->next;
        sum = x+y+c;
        if(sum/10 == 0) {
            c = 0;
        }
        else {
            c = 1;
        }
        ptr->val = sum%10;
        
        while(ptr1 != nullptr && ptr2 != nullptr) {
            x = ptr1->val;
            ptr1 = ptr1->next;
            y = ptr2->val;
            ptr2 = ptr2->next;
            sum = x+y+c;
            if(sum/10 == 0) {
                c = 0;
            }
            else {
                c = 1;
            }
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = sum%10;
        }

        while(ptr1 != nullptr) {
            x = ptr1->val;
            ptr1 = ptr1->next;
            sum = x+c;
            if(sum/10 == 0) {
                c = 0;
            }
            else {
                c = 1;
            }
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = sum%10;
        }

        while(ptr2 != nullptr) {
            y = ptr2->val;
            ptr2 = ptr2->next;
            sum = y+c;
            if(sum/10 == 0) {
                c = 0;
            }
            else {
                c = 1;
            }
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = sum%10;
        }

        if(c==1) {
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = 1;
        }

        return l;
    }
};