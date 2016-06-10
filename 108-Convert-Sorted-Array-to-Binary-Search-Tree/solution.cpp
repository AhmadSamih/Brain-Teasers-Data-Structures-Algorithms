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
        int l = 0, r = nums.size()-1;
        int mid = (l+r+1)/2;
        head = new TreeNode(nums[mid]);
        insert(head, l, mid-1, nums);
        insert(head, mid+1, r, nums);
        return head;
    }
    
    void insert(TreeNode* parent, int l, int r, vector<int>&nums){
        if(l>r) return;
        int mid = (l+r+1)/2; TreeNode *tmp;
        if(nums[mid] < parent->val) {
            parent->left = new TreeNode(nums[mid]); tmp = parent->left;
        }
        if(nums[mid] >= parent->val) {
            parent->right = new TreeNode(nums[mid]); tmp = parent->right;
        }
        if(l==r)return;
        insert(tmp, l, mid-1, nums);
        insert(tmp, mid+1, r, nums);
    }
    
};