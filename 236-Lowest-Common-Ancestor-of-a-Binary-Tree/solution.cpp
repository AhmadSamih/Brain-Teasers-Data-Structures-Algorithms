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
    TreeNode* p;
    TreeNode* q;
    TreeNode* anc;
    
    TreeNode* find(TreeNode * root){
     if(!root) return NULL;

     TreeNode* left = find(root->left);
     TreeNode* right = find(root->right);
     
     if( (left && right) || ((root==p || root==q) && (left||right)))
     {
       anc = root;
       return root;
     }

     if(root == p || root==q || left || right){
       return root;
     }
     
     return NULL;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* _p, TreeNode* _q) {
        p = _p;
        q = _q;
        find(root);
        return anc;
    }
};