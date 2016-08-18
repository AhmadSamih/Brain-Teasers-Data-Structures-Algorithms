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
    struct cmp{
      bool operator()(ListNode* a, ListNode* b){
          return a->val > b->val;
      }  
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> hp;//minheap
        
        for(int i=0; i<lists.size(); i++){
            if(lists[i])
                hp.push(lists[i]);
        }
        
        ListNode* phead = new ListNode(0);
        ListNode* tmp = phead;
        while(!hp.empty()){
            tmp->next = new ListNode(hp.top()->val);
            tmp = tmp->next;
            if(hp.top()->next)
                hp.push(hp.top()->next);
            hp.pop();
        }
        
        return phead->next;
    }
};