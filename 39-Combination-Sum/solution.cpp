class Solution {
public:
    vector<vector<int>> res;
    vector<int>tmp;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        recurr(candidates, target, 0);
        return res;
    }
    
    void recurr(vector<int>& candidates, int target, int idx){
        int sum = 0; for(int s=0; s<tmp.size();s++) sum+=tmp[s];
        if(sum == target){
            res.push_back(tmp);
            return;
        }else if(sum>target) return;

        for(int i=idx;i<candidates.size();i++){
            tmp.push_back(candidates[i]);
            recurr(candidates, target, i); //to avoid repetition, always start from the current index
            tmp.pop_back();//backtrack
        }
    }
    
};