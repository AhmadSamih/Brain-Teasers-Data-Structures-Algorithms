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
    ListNode* plusOne(ListNode* head) {

      ListNode* prev = NULL;
      ListNode* next;
      while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }
      head = prev;
      
      int carry = 1;
      prev = NULL;
      while(head){
        head->val = head->val + carry;
        if(head->val == 10){
            head->val = 0;
            carry = 1;
        }else{
          carry = 0;
        }    
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      } 
      head = prev;
      
      ListNode* n_head;
      if(carry){
        n_head = new ListNode(1);
        n_head->next = head;
        head = n_head;
      }
      
      return head;
    }
};