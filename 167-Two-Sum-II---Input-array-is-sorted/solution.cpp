class Solution {
public:
    vector<int>res;
    
    int bin_search(int diff, int start_idx, vector<int>&nums){
        int start = start_idx;
        int end = nums.size();
        int mid;
        
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==diff) return mid;
            else if(nums[mid] < diff){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty()) return res;
        
        //for each num, do binary search for difference
        for(int i=0 ;i<numbers.size();i++){
            int idx = bin_search(target - numbers[i], i+1, numbers);
            if(idx!=-1){
                res = {i+1,idx+1};
                return res;
            }
        }
        
        return res;
    }
};