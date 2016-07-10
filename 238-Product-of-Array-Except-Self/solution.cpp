class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size()==1) return {1};
        
        vector<int>res(nums.size(),1);
        vector<int>lhs(nums.size(),1);
        vector<int>rhs(nums.size(),1);

        for(int i=1, j=nums.size()-2; i<nums.size(); i++, j--){
            lhs[i] = lhs[i-1]*nums[i-1];
            rhs[j] = rhs[j+1]*nums[j+1];
        }
        
        for(int i=0; i<nums.size(); i++)
            res[i] = lhs[i]*rhs[i];
            
        return res;
    }
};