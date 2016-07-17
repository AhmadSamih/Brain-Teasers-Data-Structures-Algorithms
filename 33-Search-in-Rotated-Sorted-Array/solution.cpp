class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size()-1;
        while(l<=r){

        if(l==r) 
            if(nums[l]!=target) return -1;
            else return l;
            
        int m = (l+r)/2;
        if (nums[m] >= nums[l]) {
            if (target <= nums[m] && target >= nums[l]) r = m;
            else l = m + 1;
        } else {
            if (target > nums[m] && target <= nums[r]) l = m + 1;
            else r = m;
        }
        
        }
     return l;   
    }
};
