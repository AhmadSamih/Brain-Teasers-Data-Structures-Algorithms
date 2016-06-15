class Solution {
public:
    vector<vector<int>> vec;
    vector <int> path;
    unordered_map<int,int> used;

    vector<vector<int>> permute(vector<int>& nums) {
        DF(nums, nums.size());
        return vec;
    }
    void DF(vector<int>& nums, int size){
        if(path.size() == size){
            vec.push_back(path);
            return;
        }

        for(int i = 0; i< size; i++){
            if(used[i])continue;
            used[i]=1;
            path.push_back(nums[i]);
            DF(nums,size);
            used[i]=0;
            path.pop_back();
        }
    }
};
