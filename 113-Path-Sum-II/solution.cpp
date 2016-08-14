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
    void PathSum(TreeNode* root, int sum, vector<int> path, vector<vector<int>>& res) {
        if(!root) return;
        
        if(root && root->left==NULL && root->right==NULL && sum-root->val == 0) {
            path.push_back(root->val);
            res.push_back(path);
            return ;
        }

        path.push_back(root->val);
        PathSum(root->left, sum-root->val, path, res);
        PathSum(root->right, sum-root->val, path, res);
        path.pop_back();

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        PathSum(root, sum, {}, res);
        return res;
    }
};