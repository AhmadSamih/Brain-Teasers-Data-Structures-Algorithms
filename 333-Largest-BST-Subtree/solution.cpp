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
    unordered_map<TreeNode*,int>cache;
    
    bool isValidBST(TreeNode* root, TreeNode *min, TreeNode *max, int &num) {
           if(!root) return true;
           num+=1;
           if((max && root->val >= max->val) || (min && root->val <= min->val)) return false;
           if(isValidBST(root->left, min, root,num) && isValidBST(root->right, root, max,num)){
            cache[root] = num; return true;}
            return false;
    }

    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        int num = 0;
        if(isValidBST(root, NULL, NULL,num))
            return num;            
        else{
            int l = largestBSTSubtree(root->left);
            int r = largestBSTSubtree(root->right);
            return max(l,r);
        }
        
    }
};