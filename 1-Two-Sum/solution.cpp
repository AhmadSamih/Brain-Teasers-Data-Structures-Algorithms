class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        //vector<vector<int>>remap(nums.size(), vector<int>(2));
        int ** remap = new int * [nums.size()];
        for(int i=0; i<nums.size();i++){
            remap[i] = new int [2];
            remap[i][0] = nums[i]; remap[i][1] = i;
        }
        sort(remap, remap+nums.size(), [](int a[], int b[]){ return a[0] < b[0];});
        
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            while(remap[start][0] + remap[end][0] < target) start++;
            
            while(remap[start][0] + remap[end][0] > target) end--;
            
            if(remap[start][0] + remap[end][0] == target)
                return {remap[start][1], remap[end][1]};

        }
        /*
        unordered_map<int, int>diff;
        vector<int>res;
        for(int i=0; i<nums.size();i++){
            diff[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size();i++){
            int d = target - nums[i];
            if(diff.find(d)!=diff.end() && diff[d]!=i){
                res.push_back(i);
                res.push_back(diff[d]);
                return res;
            }
        }
        */
        return {0,0};
    }
};
