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

    TreeNode* find(TreeNode * root){
     if(!root || root==p || root==q) return root;

     TreeNode* left = find(root->left);
     TreeNode* right = find(root->right);
     
     if(left && right)
       return root;
     else
       return left?left:right;        
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* _p, TreeNode* _q) {
        p = _p;  q = _q;
        return find(root);
    }
};