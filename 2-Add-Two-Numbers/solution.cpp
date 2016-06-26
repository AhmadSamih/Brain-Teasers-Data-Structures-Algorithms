/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * tail = new ListNode(-1);
        ListNode *head  = tail;
        
        while(l1 || l2){
            int res = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            if (res>9){
                tail->next = new ListNode(res-10);
                carry =1;
            }else{
                tail->next = new ListNode(res);
                carry = 0;
            }
            tail = tail->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry) tail->next = new ListNode(1);
        return head->next;
    }
};