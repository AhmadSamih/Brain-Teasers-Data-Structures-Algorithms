class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        int size = end-start+1;
        int DP[size]= {0};
        for(int i=0; i<size;i++){
            DP[i] = max(i>0?DP[i-1]:nums[start], i>1?nums[start+i]+DP[i-2]:nums[start+i]);
        }
        return DP[size-1];
    }

    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        return max(helper(nums, 0, nums.size()-2),helper(nums, 1, nums.size()-1));
    }
};