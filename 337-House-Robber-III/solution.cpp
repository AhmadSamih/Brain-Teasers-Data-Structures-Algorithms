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
    unordered_map<TreeNode*, int>cache;
    
    int rob(TreeNode* root) {
     if(root == NULL) return 0;
     if(cache.find(root) != cache.end())
        return cache[root];
     
     int val = 0;
     if(root->left){
         val += rob(root->left->left) + rob(root->left->right);
     }   
     if(root->right){
         val += rob(root->right->left) + rob(root->right->right);
     }
     
     int _max = max( root->val + val, rob(root->left) + rob(root->right));
     cache[root] = _max;
     return _max;
    }
};