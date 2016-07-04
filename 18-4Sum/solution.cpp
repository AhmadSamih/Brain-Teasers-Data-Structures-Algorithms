class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> fourSum(vector<int>& nums, int _target) {
        sort(nums.begin(), nums.end());
        
        for(int k=0; k<nums.size();k++){
            int t = _target - nums[k];
            if(k>0 && nums[k]==nums[k-1]) continue;
            for(int i=k+1; i<nums.size(); i++){
                int target = t - nums[i];
                if(i>k+1 && nums[i]==nums[i-1]) continue;
                int start = i+1;
                int end = nums.size()-1;
                while(start<end){
                    if(start>=end) break;
                    if(nums[start]+nums[end] == target) {res.push_back({nums[k], nums[i], nums[start], nums[end]});}
                    if(nums[start]+nums[end]< target){
                        start++;
                        while(start>i+1 && nums[start]==nums[start-1]) start++;
                    }else{
                        end--;
                        while(end<nums.size()-1 && nums[end]==nums[end+1]) end--;
                    }
                }
            }
        }
        return res;
    }
};