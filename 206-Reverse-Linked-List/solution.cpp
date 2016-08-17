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
    ListNode * reverseList(ListNode* head) {
     if(!head || !(head->next)) return head;  //new_head
     ListNode * new_head = reverseList(head->next);   
     head->next->next = head;
     head->next = NULL;
     return new_head;
    }
};