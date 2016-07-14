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
    
    long sum;
    
    void DF(TreeNode*root, int n){
        if(root->left == NULL && root->right==NULL){
            sum = sum + n*10+root->val;
            return;
        }
        
        if(root->left) DF(root->left, n*10+root->val);
        if(root->right) DF(root->right, n*10+root->val);
        
        return;
    }

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        
        sum = 0;
        DF(root, 0);
        return sum;
    }
};