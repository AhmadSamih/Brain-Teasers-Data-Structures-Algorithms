class Solution {
public:
    vector<vector<int>> res;
    vector<int>tmp; int k;

    vector<vector<int>> combine(int n, int _k){
        k = _k; 
        recurr(n, 0);
        return res;
    }
    
    void recurr(int size, int idx){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<size;i++){
            tmp.push_back(i+1);
            recurr(size, i+1);
            tmp.pop_back();//backtrack
        }
    }
    
};