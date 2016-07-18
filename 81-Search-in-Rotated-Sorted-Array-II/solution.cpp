class Solution {
public:
    bool search(vector<int>& nums, int target) {
             int l = 0, r = nums.size()-1;
        while(l<=r){

        if(l==r) 
            if(nums[l]!=target) return false;
            else return true;
            
        int m = (l+r)/2;
        if (nums[m] > nums[r]) {
            if (target <= nums[m] && target >= nums[l]) r = m;
            else l = m + 1;
        } else if(nums[m] < nums[r]){
            if (target > nums[m] && target <= nums[r]) l = m + 1;
            else r = m;
        }else{
            r--;
        }
        
        }
     return true;    
    }
};