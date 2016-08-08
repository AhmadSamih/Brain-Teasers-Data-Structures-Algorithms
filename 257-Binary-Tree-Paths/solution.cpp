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
            res.push_back(path  + (path.empty() ? "" : "->") + to_string(root->val));
            return;
        }
        
        dfs(root->left, path  + (path.empty() ? "" : "->") + to_string(root->val));
        dfs(root->right, path + (path.empty() ? "" : "->") + to_string(root->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }
};