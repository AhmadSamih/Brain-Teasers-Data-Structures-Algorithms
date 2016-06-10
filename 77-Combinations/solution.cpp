class Solution {
public:
    vector<vector<int>> res;
    int n, k;

    vector<vector<int>> combine(int _n, int _k){
        vector<int> tmp(_k,0); n = _n; k = _k;
        recurr(0, 0,tmp);
        return res;
    }
    
    void recurr(int idx, int size, vector<int>&tmp){
        if(size == k){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<n;i++){
            tmp[size++]=i+1;
            recurr(i+1, size,tmp);
            size--;
        }
    }
    
};