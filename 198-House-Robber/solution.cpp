class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        int DP[nums.size()]= {0};
        DP[0] = nums[0]; DP[1] = max(nums[0],nums[1]);
        for(int i=2; i<nums.size();i++){
            DP[i] = max(DP[i-1], nums[i]+DP[i-2]);
        }
        return DP[nums.size()-1];
    }
};