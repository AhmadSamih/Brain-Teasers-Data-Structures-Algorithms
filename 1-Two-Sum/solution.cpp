class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
        
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<vector<int>>remap(nums.size(), vector<int>(2));
        for(int i=0; i<nums.size(); i++)
            remap[i] = {nums[i],i};
        sort(remap.begin(), remap.end(), cmp);
        
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            if(remap[start][0] + remap[end][0] == target)
                return {remap[start][1], remap[end][1]};
            
            if(remap[start][0] + remap[end][0] < target)
                start++;
            else
                end--;
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
