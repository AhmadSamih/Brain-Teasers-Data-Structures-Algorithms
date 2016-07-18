class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<2)return;
        
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size();i+=2){
            if(i+1 <nums.size()) swap(nums[i], nums[i+1]);
        }
    }
};