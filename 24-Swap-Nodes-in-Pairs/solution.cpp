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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode* next;
        ListNode* nhead = head->next == NULL ? head : head->next;
        ListNode *pre = NULL;
        while(head && head->next){
            next = head->next;
            head->next = head->next->next;
            next->next = head;
            if(pre) pre->next = next;
            pre = head;
            head = head->next;
        }
        return nhead;
    }
};

