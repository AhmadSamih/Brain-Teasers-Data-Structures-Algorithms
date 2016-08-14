class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        int size = nums.size();
        int s1 = (size*(size+1))/2;
        
        int tmp = 0;
        for(auto &num:nums) 
            tmp+=num;
        
        return (s1 - tmp);
        */
        int res1 = 0;
        for(auto &num:nums)
            res1 ^= num;
            
        vector<int>res= {nums.size(),1,nums.size()+1,0};
        int res2 = res[(nums.size())%4];

        return res1 ^ res2;
    }
};