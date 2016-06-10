class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int n, k;

    vector<vector<int>> combine(int _n, int _k){
        tmp.resize(_k,0); n = _n; k = _k;
        recurr(0, 0);
        return res;
    }
    
    void recurr(int idx, int size){
        if(size == k){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<n;i++){
            tmp[size++]=i+1;
            recurr(i+1, size);
            size--;
        }
    }
    
};