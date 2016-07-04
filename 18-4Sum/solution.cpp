class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int _target) {
	    vector<vector<int>>res;
		
		if(nums.empty()) 
		    return res;
        
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int k=0; k<size;k++){
            while(k>0 && nums[k]==nums[k-1]) k++;
            
            int t = _target - nums[k];
            for(int i=k+1; i<size; i++){
                while(i>k+1 && nums[i]==nums[i-1]) i++;
                
                int target = t - nums[i];
                int start = i+1; int end = size - 1;
        
                while(start<end){
                    if(nums[start]+nums[end]< target) start++;
                    else if(nums[start]+nums[end] > target) end--;
                    else{
                        res.push_back({nums[k], nums[i], nums[start], nums[end]}); 
                        start++; end--;
                    }
                    while(start>i+1 && nums[start]==nums[start-1]) start++;
                    while(end<nums.size()-1 && nums[end]==nums[end+1]) end--;
                }
            }
        }
        return res;
    }
};