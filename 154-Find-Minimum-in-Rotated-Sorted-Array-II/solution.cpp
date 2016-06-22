class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            if(l == r) return nums[l];
            int mid = (l+r)/2;
            if(nums[mid]>nums[r]){
                l = mid+1;
            }else if(nums[mid]<nums[r]){
                r = mid;
            }else{
                r--;//move closer to left and try
            }
        }
     return l;
    }
};