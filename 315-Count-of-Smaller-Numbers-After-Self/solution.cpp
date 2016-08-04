class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size()); 
        vector<int> sorted;
        for(int i = nums.size()-1; i>=0; i--){
            auto idx = lower_bound(sorted.begin(), sorted.end(), nums[i]); 
            result[i] = idx-sorted.begin();
            sorted.insert(idx,nums[i]);
        }
        return result;
    }
};