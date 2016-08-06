class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::less<int>>heap;
        
        for(int i=0; i<nums.size(); i++){
            heap.push(nums[i]);
        }
        
        int _k= 1;
        while(!heap.empty()){
            if(_k++ == k)
                return heap.top();
            heap.pop();
        }
        
        return -1;
    }
};