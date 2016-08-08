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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        
        stack<TreeNode*>stk;
        while(root){
            stk.push(root);
            root=root->left;
        }
        
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            
            if(tmp->right){
                tmp = tmp->right;
                while(tmp){
                    stk.push(tmp);
                    tmp=tmp->left;
                }
            }
        }
        return res;
    }
};