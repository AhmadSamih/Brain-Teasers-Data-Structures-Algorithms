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
   int count(TreeNode* root){
       if(!root) return 0;
       return 1+count(root->left) + count(root->right);
   }
    
   int kthSmallest(TreeNode* root, int k) {
       int cnt = count(root->left);
       if(k<=cnt){
          return kthSmallest(root->left, k);
       }else if(k>cnt+1){
           return kthSmallest(root->right, k-cnt-1);
       }
       return root->val;
   }
};