class Solution {
public:
    vector<vector<int>> res;
    vector<int>tmp; int target;
    int size;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int _target) {
        sort(candidates.begin(), candidates.end());
        target = _target; size = candidates.size();
        recurr(candidates, 0, 0);
        return res;
    }
    
    void recurr(vector<int>& candidates, int idx, int sum){
        if(sum == target){
            res.push_back(tmp);
            return;
        }else if(sum>target) return;

        for(int i=idx;i<size;i++){
            tmp.push_back(candidates[i]);
            recurr(candidates, i, sum+candidates[i]); //to avoid repetition, always start from the current index
            tmp.pop_back();//backtrack
        }
    }
    
};