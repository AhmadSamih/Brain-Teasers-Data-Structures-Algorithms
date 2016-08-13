class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        tuple<int,int,int> last_tup;
        int last_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];
            int start = i+1; int end = nums.size()-1;
            while(start<end){
                if(abs(rem - (nums[start]+nums[end])) < last_diff){
                    last_diff = abs(rem - (nums[start]+nums[end]));                
                    last_tup = make_tuple(i, start, end);
                }
                
                if(rem > (nums[start]+nums[end])){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return nums[get<0>(last_tup)] + nums[get<1>(last_tup)] + nums[get<2>(last_tup)];
    }
};