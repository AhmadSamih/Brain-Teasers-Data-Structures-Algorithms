class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp; int size = nums.size();
        for(int i=size-1;i>=0;i--){
            int cnt = ++mp[nums[i]];
            if(cnt > 1) return true;
        }
        return false;
    }
};