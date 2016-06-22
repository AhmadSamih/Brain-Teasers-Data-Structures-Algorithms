class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int curr_max =nums[0];
        int max_so_far = nums[0];
        
        for(int i=1; i<size;i++){
            curr_max = std::max(curr_max+nums[i], nums[i]);
            max_so_far = std::max(max_so_far, curr_max);
        }
        
        return max_so_far;
    }
};