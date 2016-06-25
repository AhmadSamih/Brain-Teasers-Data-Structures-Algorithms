class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>diff;
        vector<int>res;
        for(int i=0; i<nums.size();i++){
            diff[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size();i++){
            int d = target - nums[i];
            if(diff.find(d)!=diff.end() && diff[d]!=i){
                res.push_back(i);
                res.push_back(diff[d]);
                return res;
            }
        }
        return res;
    }
};