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
    TreeNode* dfs(TreeNode* root){
        if(!root) return NULL;
        
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        
        if(left){
            root->right = left;
            root->left = NULL;
        }
        
        while(left && left->right){
            left=left->right;
        }
        
        if(left){
            left->right = right;
            left->left = NULL;
        }
        
        return root;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};