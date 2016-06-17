class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
        if(strs.size()==1) return strs[0];
        
        int idx = 0,i=0;
        int not_found = 0;
        for(i=0; i<strs[0].size(); i++){
            not_found = 0;
            for(int j=1; j<strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    not_found = 1;
                    break;
                }
            }
            if(not_found) {idx = i; break;}
            else{idx=i+1;}
        }
        
        string res = strs[0].substr(0,idx);
        return res;
    }
};