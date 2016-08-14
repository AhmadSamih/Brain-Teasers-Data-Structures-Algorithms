/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //idea is to store a hashmap of mapping between old and new
        unordered_map<RandomListNode*,RandomListNode*>mapping;
        
        RandomListNode* p_head = new RandomListNode(0);
        RandomListNode* n_head = p_head;
        RandomListNode* tmp = head;
        while(tmp){
            n_head->next = new RandomListNode(tmp->label);
            mapping[tmp] = n_head->next;
            tmp = tmp->next;
            n_head = n_head->next;
        }
        
        tmp = head;
        n_head = p_head->next;
        while(tmp){
            if(tmp->random)
                n_head->random = mapping[tmp->random];
            tmp = tmp->next;
            n_head = n_head->next;
        }
        
        return p_head->next;
    }
};