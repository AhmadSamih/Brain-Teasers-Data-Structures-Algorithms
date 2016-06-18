class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>cache;
        for(int i=0; i<nums.size();i++){
            if(cache.find(nums[i]) != cache.end()){
                if(i - cache[nums[i]] <=k)
                    return true;
            }
            cache[nums[i]] = i; 
        }
        return false;
    }
};