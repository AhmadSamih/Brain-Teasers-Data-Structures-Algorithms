class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<2)return;
        for(int i=1; i<nums.size();i++){
            if((i&0x1 && nums[i]<nums[i-1]) || (!(i&0x1) && nums[i]>nums[i-1]))
                swap(nums[i], nums[i-1]);
        }
    }
};