class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int found = 0; int pos;
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                found = 1;            
                set<int>_set(nums.begin()+i, nums.end());
                auto idx = _set.find(nums[i]);
                int next = *(++idx);
                for(int k=nums.size()-1; k>=0; k--) 
                    if(nums[k] == next) {
                        pos = k; break;
                    }
                int tmp2 = nums[i];
                nums[i] = next;        
                nums[pos] = tmp2;
                sort(nums.begin()+i+1, nums.end());
                //cout <<i << " " << pos <<endl;
                break;
            }
        }
        if(!found)sort(nums.begin(), nums.end());
    }
};