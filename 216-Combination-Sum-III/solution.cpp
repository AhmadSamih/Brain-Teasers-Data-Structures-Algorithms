class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int n, int k){
        vector<int> tmp; 
        int sum = 0;
        recurr(k, n, 1, tmp, sum);
        return res;
    }
    
    void recurr(int n, int k, int idx, vector<int>&tmp, int sum){
        if((sum == n) && (tmp.size()==k)){
            res.push_back(tmp);
            return;
        }else if (sum>n || tmp.size()>k) return;
        
        for(int i=idx;i<=9;i++){
            tmp.push_back(i);
            recurr(n, k, i+1, tmp, sum+i);
            tmp.pop_back();
        }
    }
    
};