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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root)return vector<vector<int>>();
        vector<vector<int>> res;    
        queue<pair<TreeNode*,int>>q;
        int depth = 0;
        int last_depth = depth;
        q.push(make_pair(root,depth+1));
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int d = q.front().second;
            if(d == last_depth){
                res[d-1].push_back(node->val);    
            }else{
                res.push_back({node->val});
            }
            last_depth = d;
            if(node->left)
                q.push(make_pair(node->left, d+1));
            if(node->right)
                q.push(make_pair(node->right, d+1));
            
            q.pop();
        }
        
        return res;
    }
};