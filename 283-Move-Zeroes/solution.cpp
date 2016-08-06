class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     if(nums.size() <=1) return;
     int l =0; int r = 1;
     while(l<nums.size() && r<nums.size()){
         if(nums[l] == 0){
             while(r<nums.size() && nums[r] == 0)r++;
             if(r>=nums.size()) break;
             nums[l] = nums[r];
             nums[r] = 0;
             r++;
         }
         l++;
         r=l+1;
     }
    }
};