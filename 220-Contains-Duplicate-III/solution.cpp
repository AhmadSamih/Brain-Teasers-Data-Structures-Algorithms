class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(!nums.size() || !k) return false;
        vector<int>bst;
        for(int i=0; i<nums.size(); i++)
        {
            const auto it = lower_bound(bst.begin(), bst.end(), nums[i] - t);
            if(it != bst.end() && abs(*it - nums[i]) <= t) return true;
            bst.insert(it, nums[i]);
            if(bst.size() > k) bst.erase( find(bst.begin(), bst.end(), nums[i-k]) );
        }
        return false;
    }
};