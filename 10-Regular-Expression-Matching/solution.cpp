class Solution {
public:

    bool helper(string s, int si, string p, int pi){
        if(si >= s.size() && pi>= p.size())
            return true;
            
        if(pi<p.size()-1 && p[pi+1]=='*'){
            return helper(s, si, p, pi+2) || ( (s[si]==p[pi] || p[pi]=='.') && si<s.size() && helper(s, si+1, p, pi));
        }else
            return ((s[si] == p[pi] || p[pi] == '.') && si<s.size() && pi<p.size() && helper(s, si+1, p, pi+1));
    }

    bool isMatch(string s, string p) {
        vector<vector<bool>>dp(s.size()+1, vector<bool>(p.size(), false));
      
        //i=0, j=0, empty strings
        dp[0][0] = true;
        
        for(int i=1;i<=p.size();i++){
            if(p[i-1] == '*')
                dp[0][i] = (i>1 && dp[0][i-2]);
        }
        
        //handle corner case of .* with empty string s
        
        for(int i=1; i<=s.size();i++){
            for(int j=1;j<=p.size(); j++){
                if(p[j-1]=='+'){
                    
                }else if(p[j-1] =='*'){
                    dp[i][j] = (j>1 && dp[i][j-2]) || ((s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                }else{
                 dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='.') && dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};