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
        int depth = 1;
        q.emplace(root,1);
        int new_level = 1;
        vector<int>lev;
        int last_level = 0;
        while(!q.empty()){
            TreeNode* tmp = q.front().first;
            int d = q.front().second;
            if(d != last_level)
                new_level = 1;
            last_level = d;
                
            q.pop();
            if(tmp->left)
                q.emplace(tmp->left, d+1);
            if(tmp->right)
                q.emplace(tmp->right, d+1);
            if(new_level){
                if(lev.size()) 
                    res.insert(res.begin(), lev);
                new_level = 0;
                lev.clear();
                lev.push_back(tmp->val);
            }else{
                lev.push_back(tmp->val);
            }
        }
        if(lev.size())
            res.insert(res.begin(), lev);
        return res;
    }
};