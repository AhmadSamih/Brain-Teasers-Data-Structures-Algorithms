class Solution {
public:
    vector<vector<int>>res;
    unordered_map<int, int>used;
    void recur(vector<int>tmp, int n, int k, int idx){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }

        for(int i=idx ; i<=n; i++){
            tmp.push_back(i);
            recur(tmp, n, k, i+1);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        recur(vector<int>(), n, k,1);
        return res;
    }
};