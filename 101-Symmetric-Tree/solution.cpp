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

    bool rec(TreeNode* left, TreeNode *right){
        if(left==NULL && right==NULL)return true;
        if(left==NULL || right==NULL)return false;
        
        bool left_right = (left->val == right->val) && rec(left->left, right->right);
        bool right_left = (left->val == right->val) && rec(left->right, right->left);
        
        return (left_right && right_left);
    }

    bool isSymmetric(TreeNode* root) {
        return rec(root, root);
    }
};