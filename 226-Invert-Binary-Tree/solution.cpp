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
    void mirror(TreeNode* root){
        if(!root) return;
        
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirror(root->left);
        mirror(root->right);
        
    /*    if(!left || !right) return;
        cout<<"hello\n";
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
        mirror(left->left, right->right);
        mirror(left->right, right->left);
      */  
    }
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }
};