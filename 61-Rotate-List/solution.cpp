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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int count = 1;
        ListNode* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
            count++;
        }
        k %= count;
        
        if(k==0)return head;
        
        ListNode* n_head;
        ListNode* tail = head;
        int c = count - k - 1;
        while(c--){
            tail = tail->next;
        }
        
        n_head = tail->next;
        tail->next = NULL;
        tmp->next = head;
        
        return n_head;
      
    }
};