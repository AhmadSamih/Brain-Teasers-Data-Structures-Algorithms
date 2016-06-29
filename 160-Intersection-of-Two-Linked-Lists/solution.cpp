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
        
        if((headA && !headB) || (!headA && headB)) return NULL;
        
        ListNode *A = headA;
        ListNode *B = headB;
        
        int traversedA = 0;
        int traversedB = 0;      
        
        while(1){
            if(headA == headB)
                return headA;
                        
            headA = headA->next;
            headB = headB->next;
            
            if(headA ==NULL){
                if(traversedA) return NULL;
                traversedA = 1;
                headA = B;
            }
            if(headB ==NULL){
                if(traversedB) return NULL;
                traversedB = 1;
                headB = A;
            }
        }
    }
};


/*
  1 1
        1 1 1
1 1 1
 
*/