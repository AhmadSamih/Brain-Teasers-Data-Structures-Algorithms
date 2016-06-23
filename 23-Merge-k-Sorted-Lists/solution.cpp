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
    
    /*algo works like this: store all k first elements from the lists in a min heap, 
    store the min somewhere, replace it with another node from the list.*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto cmp = [](ListNode* left, ListNode* right) { return (left->val) > (right->val);};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>heap(cmp);
        
        //maintain a k-ary heap
        for(int i=0; i<lists.size();i++){
            if(lists[i])
                heap.push(lists[i]);
        }

        ListNode *root = NULL, *curr = NULL;
        ListNode *tmp = heap.empty() ? NULL : heap.top();

        if(tmp){
            root = new ListNode(tmp->val);
            curr = root;
            heap.pop();
            if(tmp->next)
                heap.push(tmp->next);
        }

        //create the resulting list
        while(!heap.empty()){
            ListNode *tmp = heap.top();
            curr->next = new ListNode(tmp->val);
            curr = curr->next;
            heap.pop();
            if(tmp->next)
                heap.push(tmp->next);
        }

        return root;
    }
};