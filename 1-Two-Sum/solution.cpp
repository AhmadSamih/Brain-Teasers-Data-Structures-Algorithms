class Solution {
public:

    static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.first<b.first;
    }
        
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> remap(nums.size());
        for(int i=0; i<nums.size(); i++)
            remap[i] = {nums[i],i};
        sort(remap.begin(), remap.end(), cmp);
        
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            
            if(remap[start].first + remap[end].first == target)
                return {remap[start].second, remap[end].second};
            
            if(remap[start].first + remap[end].first < target)
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
