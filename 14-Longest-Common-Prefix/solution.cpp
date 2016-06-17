class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int i=0, not_found = 0;
        for(i=0; i<strs[0].size(); i++){
            for(int j=1; j<strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    not_found = 1;
                    break;
                }
            }
            if(not_found) break;
        }
        string res = strs[0].substr(0,i);
        return res;
    }
};