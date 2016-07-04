class Solution {

public:
    unordered_map<int, int>diff;
    vector<vector<int>>res;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size();i++){
            diff[nums[i]] = i;
        }
        vector<int> tmp;
        for(int i=0; i<nums.size(); i++){
            int target = - nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int d = target - nums[j];
                if(diff.find(d)!=diff.end() && diff[d]!=j && diff[d]>=j){
                    res.push_back({nums[i], nums[j], d});
                }
            }
        }
        return res;
    }
};