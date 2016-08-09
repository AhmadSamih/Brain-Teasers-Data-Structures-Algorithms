class Solution {
public:

    bool ispal(string tmp){
        int start =0;
        int end = tmp.size()-1;
        while(start<=end){
            if(tmp[start++] != tmp[end--])
                return false;
        }
        return true;
    }

    vector<vector<string>>res;
    void dfs(string s, int idx, vector<string>&path){
        if(idx == s.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=idx; i<s.size(); i++){
            string tmp = s.substr(idx, i-idx+1);
            if(ispal(tmp)){
             //pushback   
             path.push_back(tmp);
             dfs(s, i+1, path);
             path.pop_back();
             //popback
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if(s.empty())return res;
        vector<string>path;
        dfs(s, 0, path);
        return res;
    }
};