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
    bool isValidBST(TreeNode* root, TreeNode *min, TreeNode *max) {
           if(!root) return true;
           if((max && root->val >= max->val) || (min && root->val <= min->val)) return false;
           return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};