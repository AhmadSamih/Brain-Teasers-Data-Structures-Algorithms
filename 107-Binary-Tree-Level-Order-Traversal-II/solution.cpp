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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>res; if(!root) return res;
        q.emplace(root,1);

        vector<int>lev;
        int last_level = 0;
        while(!q.empty()){
            TreeNode* tmp = q.front().first;
            int d = q.front().second;
            q.pop();
            
            if(tmp->left)
                q.emplace(tmp->left, d+1);
            
            if(tmp->right)
                q.emplace(tmp->right, d+1);
            
            //if(d != last_level && lev.size()){
            if(d != last_level){
                res.insert(res.begin(), {tmp->val});
            }else
            //lev.push_back(tmp->val);
            res[0].push_back(tmp->val);
            
            last_level = d;
        }
        
        //if(lev.size())
            //res.insert(res.begin(), lev);
            
        return res;
    }
};