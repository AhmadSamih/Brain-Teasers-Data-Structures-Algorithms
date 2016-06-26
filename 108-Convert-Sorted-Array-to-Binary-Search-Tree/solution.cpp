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
        //do binary search/insertion
        int left = 0; int right = nums.size();
        return BS(nums, left, right);
    }
    
    TreeNode* BS(vector<int>&nums, int left, int right){
        if(left >= right) return NULL;
        int mid = (left+right)/2; 
        TreeNode *node = new TreeNode(nums[mid]);
        node->left  = BS(nums, left, mid );//left
        node->right = BS(nums, mid+1, right );//right
        return node;        
    }
};