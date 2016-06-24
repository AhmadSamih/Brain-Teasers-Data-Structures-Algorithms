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
        
        //Using Lambda function
        //auto cmp = [](ListNode* left, ListNode* right) { return (left->val) > (right->val);}
        //priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>heap(cmp);
    
        //using functor
        struct cmp{ bool operator()(ListNode* left, ListNode* right){return (left->val) > (right->val);}};
        priority_queue<ListNode*, vector<ListNode*>,cmp>heap;

        //maintain a k-ary heap
        for(int i=0; i<lists.size();i++){
            if(lists[i])
                heap.push(lists[i]);
        }

        ListNode *root = new ListNode(0);
        ListNode *tail = root;
        //create the resulting list
        while(!heap.empty()){
            ListNode *tmp = heap.top(); heap.pop();
            tail->next = new ListNode(tmp->val);
            tail = tail->next;
            if(tmp->next)
                heap.push(tmp->next);
        }
        return root->next;
    }
};