class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::less<int>>heap;
        
        for(int i=0; i<nums.size(); i++)
            heap.push(nums[i]);
        
        for(int i=0; i<k-1; i++)
            heap.pop();
            
        return heap.top();
        /*
        sort(nums.begin(), nums.end(), [](int &a, int &b){return a>b;});
        return nums[k-1];
        */
    }
};