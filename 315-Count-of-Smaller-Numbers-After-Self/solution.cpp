class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        //could be also done using a BST. 
        int s = nums.size();
        vector<int> result; if(nums.empty())return result;
        result.resize(nums.size());
        
        vector<int> sorted;
        sorted.insert(sorted.begin(),nums[s-1]);
        result[s-1] = 0;
        for(int i = s-2; i>=0; i--){
            auto idx = lower_bound(sorted.begin(), sorted.end(), nums[i]); //bs(sorted, nums[i]);
            result[i] = idx-sorted.begin();
            sorted.insert(idx,nums[i]);
        }
        return result;
    }
    
    int bs(vector<int>& sorted, int num){
        if(sorted.empty())return 0;
        
        int l = 0;
        int r = sorted.size();
        int x = 0;
        while(l<r){
            int mid = (l+r-1)/2;
            if(num>sorted[mid]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        
         return l;
        
        return 0;

    }
};