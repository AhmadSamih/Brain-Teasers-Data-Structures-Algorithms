class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int _min, mid;
        while(left<=right){
            mid = (left+right)/2;
            if(left==right){
                _min = nums[left];
                break;
            }
            if(nums[right]<nums[mid]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return _min;
    }
};