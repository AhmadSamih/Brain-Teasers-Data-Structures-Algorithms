class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> result;
        unordered_map<string, int>cache;
        for(int i=0; i<words.size(); i++)
            cache[words[i]] = i;
            
        for(int i=0; i<words.size(); i++){
            
            for(int k=0; k<=words[i].size(); k++){
                
                string left = words[i].substr(0, k);
                string right = words[i].substr(k);
                
                string rleft = left; reverse(rleft.begin(), rleft.end());
                string rright = right; reverse(rright.begin(), rright.end());
                
                if(right == rright && cache.count(rleft) && cache[rleft]!=i){
                    result.push_back({i, cache[rleft]});
                }
                if(k&& left == rleft && cache.count(rright) && cache[rright]!=i){
                    result.push_back({cache[rright], i});
                }
            }
        }
        return result;
    }
};