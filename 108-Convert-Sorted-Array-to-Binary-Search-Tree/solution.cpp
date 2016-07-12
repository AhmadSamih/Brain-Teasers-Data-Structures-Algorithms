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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())return NULL;
        return DF(0, nums.size(), nums);
    }
    
    TreeNode * DF(int left, int right, vector<int>&nums){
        if(left>=right)return NULL;
        int mid = (left+right)/2;
        
        TreeNode * tmp = new TreeNode(nums[mid]);
        tmp->left = DF(left, mid, nums);
        tmp->right = DF(mid+1, right, nums);
        
        return tmp;
    }
};