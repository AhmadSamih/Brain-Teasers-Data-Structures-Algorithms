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
    void PathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
        if(!root) return;
        
        path.push_back(root->val);
        if(!root->left && !root->right && sum==root->val)
            res.push_back(path);//its ok to return from here, but if you pass path by reference, then if you return, it wouldn't pop back

        if(root->left) PathSum(root->left, sum-root->val, path, res);
        if(root->right) PathSum(root->right, sum-root->val, path, res);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int>path;
        PathSum(root, sum, path, res);
        return res;
    }
};