class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int found = 0; int pos;
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                found = 1;            
                int value = INT_MAX;
                for(int k=nums.size()-1; k>i; k--) 
                    if(nums[k] > nums[i]) {
                        if(nums[k]<value){
                            value = nums[k];
                            pos = k;
                        }
                    }
                int tmp2 = nums[i];
                nums[i] = nums[pos];        
                nums[pos] = tmp2;
                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
        if(!found)sort(nums.begin(), nums.end());
    }
};