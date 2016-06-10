class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combine(int n, int k){
        vector<int>tmp(k,0);
        recurr(n, k, 0, 0, tmp);
        return res;
    }
    
    void recurr(int n, int k, int idx, int size, vector<int>& tmp){
        if(size == k){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<n;i++){
            tmp[size++]=i+1;
            recurr(n, k, i+1, size, tmp);
            size--;
        }
    }
    
};