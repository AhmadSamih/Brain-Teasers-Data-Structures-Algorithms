class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int last_rem = 0;
        int last_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];
            int start = i+1; int end = nums.size()-1;
            while(start<end){
                if(abs(rem - (nums[start]+nums[end])) < last_diff){
                    last_diff = abs(rem - (nums[start]+nums[end]));                
                    last_rem = nums[i]+ nums[start] + nums[end];
                }
                
                if(rem > (nums[start]+nums[end])){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return last_rem;
    }
};