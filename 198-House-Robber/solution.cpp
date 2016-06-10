class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int DP[nums.size()] = {0};        
        DP[0] = nums[0];
        if(nums.size() > 1) DP[1] = max(nums[1], DP[0]);
        for(int i=2; i<nums.size(); i++){
                DP[i] = max(DP[i-1], DP[i-2]+nums[i]);
        }
        return DP[nums.size()-1];
    }
};