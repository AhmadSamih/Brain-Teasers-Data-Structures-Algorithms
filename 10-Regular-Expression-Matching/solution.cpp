class Solution {
public:
    bool isMatch(string s, string p) {
        
        vector<vector<bool>>DP(s.size()+1, vector<bool>(p.size()+1,0));

        DP[0][0] = true;

        for(int i=1; i<=p.size();i++){
            if(i>1 && p[i-1]=='*')
                DP[0][i] = DP[0][i-2];
        }
        
        for(int i=1; i<=s.size();i++){
            for(int j=1; j<=p.size(); j++){
                if(p[j-1]=='*'){
                    DP[i][j] = (j>1 && DP[i][j-2]) || (s[i-1] == p[j-2] || p[j-2] == '.')&& DP[i-1][j];
                }else{
                    if(s[i-1] == p[j-1] || p[j-1] == '.')
                        DP[i][j] = DP[i-1][j-1];
                }      
            }
        }
    return DP[s.size()][p.size()];
    }
};