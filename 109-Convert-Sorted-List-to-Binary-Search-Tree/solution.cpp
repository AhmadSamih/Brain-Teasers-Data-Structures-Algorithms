/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return DF(head,NULL);
    }
    
    TreeNode * DF(ListNode* left, ListNode* right){
        
	    if( left == right )
    		return NULL;
    	if( left->next == right )    // 
    	{	
    		TreeNode *root = new TreeNode( left->val );
    		return root;
    	}        
    	
        ListNode* mid, *tmp;
        mid = left;
        tmp = left;
        while(tmp!=right && tmp->next!=right){
            tmp=tmp->next->next;
            mid=mid->next;
        }

        TreeNode * res = new TreeNode(mid->val);
        res->left = DF(left, mid);
        res->right = DF(mid->next, right);
        
        return res;
    }
};