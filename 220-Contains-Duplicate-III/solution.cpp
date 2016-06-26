class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int _t) {
        if(!nums.size() || !k) return false;
        vector<long long>bst;
        for(int i=0; i<nums.size(); i++)
        {
            //const auto it = lower_bound(bst.begin(), bst.end(), nums[i] - t);
            //if(it != bst.end() && abs(*it - nums[i]) <= t) return true;
            
            const auto it = lower_bound(bst.begin(), bst.end(), nums[i]);
            int idx = it - bst.begin();
            long long num = nums[i];
            long long t = _t;
            if( idx>=0 && idx < bst.size() && abs(bst[idx]-  nums[i])<=t ) return true;
            if( idx>0 && idx <= bst.size() && abs(bst[idx-1]-nums[i])<=t ) return true;

            bst.insert(it, nums[i]);
            if(bst.size() > k) bst.erase( find(bst.begin(), bst.end(), nums[i-k]) );
        }
        return false;
    }
};