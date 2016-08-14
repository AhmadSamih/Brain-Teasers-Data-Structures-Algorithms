class Solution {
public:
    unordered_map<string,bool>cache;
    bool dfs(string s, int idx, unordered_set<string>& wordDict, string tmp){
        if(idx == s.size())
            return true;

        if(cache[tmp])
            return false;

        for(int i=idx; i<s.size(); i++){
            string tmp = s.substr(idx, i-idx+1);
            if(wordDict.count(tmp)){
             if(dfs(s, i+1, wordDict, tmp)){
                return true;
             }
            }
        }
        
        cache[tmp] = true;
        return false;
    }

    bool wordBreak(string s, unordered_set<string>& wordDict) {
        return dfs(s, 0, wordDict, "");

    }
};