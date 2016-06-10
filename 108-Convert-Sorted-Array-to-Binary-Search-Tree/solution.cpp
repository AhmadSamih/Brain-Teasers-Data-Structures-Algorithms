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
    TreeNode *head;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return head;
        return insert(0, nums.size()-1, nums);
    }
    
    TreeNode* insert(int l, int r, vector<int>&nums){
        if(l>r) return NULL;
        int mid = (l+r+1)/2; TreeNode* root = new TreeNode(nums[mid]);
        root->left = insert(l, mid-1, nums); 
        root->right = insert(mid+1, r, nums);
        return root;
    }
    
};