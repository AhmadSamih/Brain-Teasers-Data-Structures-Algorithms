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
    vector<string>res;
    void dfs(TreeNode* root, string path){
        if(!root)return;
        
        if(!root->left && !root->right) {
            path = path+"->" + to_string(root->val);
            res.push_back(path);
            return;
        }
        
        dfs(root->left, path + "->" + to_string(root->val));
        dfs(root->right, path + "->" + to_string(root->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return vector<string>();
        if(!root->left && !root->right) return {to_string(root->val)};
        dfs(root->left, to_string(root->val));
        dfs(root->right, to_string(root->val));
        return res;
    }
};