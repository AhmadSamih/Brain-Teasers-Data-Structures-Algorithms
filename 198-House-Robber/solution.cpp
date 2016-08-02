class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        vector<int>DP(nums.size(), 0);
        DP[0] = nums[0];
        if(nums.size() ==1) return DP[0];
        DP[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size();i++){
            DP[i] = max(nums[i]+DP[i-2], DP[i-1]);
        }
        return DP[nums.size()-1];
    }
};