class Solution {
public:
    
    vector<vector<int>> vec;
    vector <int> path;
    vector <bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(),false);
        sort(nums.begin(), nums.end());
        DF(nums, nums.size());
        return vec;
    }
    void DF(vector<int>& nums, int size){
        if(path.size() == size)
            vec.push_back(path);
        /*note: to retain a value in a recursive function, make it public*/
        for(int i = 0; i< size; i++){
            if(used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1])){continue;}
            path.push_back(nums[i]);
            used[i] = true;
            DF(nums,size);
            path.pop_back();
            used[i] = false;
        }
    }
};