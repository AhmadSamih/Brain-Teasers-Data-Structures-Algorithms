class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     
        if(nums.empty())return 0;           
        vector<int>DP(nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                    DP[i] = max(DP[i], DP[j]+1);
            }
        }
        return *max_element(DP.begin(), DP.end());
    }
};

//This is quite different from the 2D max increasing sequence. Beucase that one is consequtive. 