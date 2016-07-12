class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        vector<int>dq;
        for(int i=0; i<nums.size(); i++){
            //find if the diff of less than t exists
            auto itr = lower_bound(dq.begin(), dq.end(), nums[i]-t);
            if(itr != dq.end() && abs(*itr-nums[i])<=t) return true;

            //push new one to deque
            dq.insert(lower_bound(dq.begin(), dq.end(), nums[i]), nums[i]);
            
            //elimintate first if bigger than k
            if(dq.size()>k)
                dq.erase( find(dq.begin(), dq.end(), nums[i-k]) );
        }
        return false;
    }
};
        