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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (!headA || !headB) return NULL;
      if (headA == headB) return headA;
        ListNode *tailA=headA;
        while (tailA->next) tailA=tailA->next;
        tailA->next = headB; //create a circle
        ListNode *slow=headA,*fast=headA;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (slow==fast){
                fast = headA;
                while (fast!=slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                tailA->next = NULL;
                return fast;
            }
        }
        tailA->next = NULL;
        return NULL;
    }
};