class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] !=0)
                nums[j++] = nums[i];
                if(i!=(j-1)) nums[i] = 0;
        }
    }
};