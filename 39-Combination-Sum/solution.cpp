class Solution {
public:
    vector<vector<int>> res;
    unordered_map<string, int>seen;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>tmp;
        sort(candidates.begin(), candidates.end());
        recurr(candidates, tmp, target);
        return res;
    }
    
    void recurr(vector<int>& candidates, vector<int>&tmp, int target){
        int sum = 0; for(auto s:tmp) sum+=s;
        if(sum == target){
            vector<int> tmp2 = tmp;
            sort(tmp2.begin(), tmp2.end());
            string str = "";
            for(auto x:tmp2) str+=to_string(x);
            if(seen[str]) return;
            seen[str] = 1;
            res.push_back(tmp2);
            return;
        }else if(sum>target) return;

        for(int i=0;i<candidates.size();i++){
            tmp.push_back(candidates[i]);
            recurr(candidates, tmp, target);
            tmp.pop_back();//backtrack
        }
    }
    
};