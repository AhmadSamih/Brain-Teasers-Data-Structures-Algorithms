class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> res;
        
        unordered_map<string, int>cache;
        for(int i=0;i<words.size();i++){
            cache[words[i]]=i;
        }
        
        for(int i=0; i<words.size();i++){
            for(int j=0; j<=words[i].size();j++){
                string left =  words[i].substr(0,j);
                string right = words[i].substr(j);
                string rleft = left; reverse(rleft.begin(), rleft.end());
                string rright = right; reverse(rright.begin(), rright.end());
                if(cache.find(rleft)!=cache.end() && cache[rleft]!=i && right==rright ){
                    res.push_back({i,cache[rleft]});
                }
                if(j && cache.find(rright)!=cache.end() && cache[rright]!=i && left==rleft ){
                    res.push_back({cache[rright],i});
                }
            }
        }
        return res;
    }
};