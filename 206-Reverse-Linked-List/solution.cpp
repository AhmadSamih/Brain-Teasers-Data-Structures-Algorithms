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
    ListNode * new_head;
    void _reverseList(ListNode* head) {
     if(head->next==NULL){
         new_head = head;
        return;  
     }
     reverseList(head->next);   
     head->next->next = head;
    }

    
    ListNode* reverseList(ListNode* head) {
      if(head == NULL) return NULL;
      
     _reverseList(head);   
     head->next = NULL;
     return new_head;
    }
};