class Solution {
public:
    bool isMatch(string s, string p) {
       int m = s.size(), n = p.size(); 
       vector<vector<bool>> _ismatch(m + 1, vector<bool>(n + 1));
       _ismatch[0][0] = true;

      //convert ****** => *
      string pd = "";
      for(int i =0; i<n; ){
          pd += p[i];
          if(p[i] == '*'){
                while(p[i] == '*') i++;
          }else{
            i++;
          }
      }

      n = pd.size();
      if(pd[0] == '*') 
        _ismatch[0][1] =  true;

      for(int i =1; i<=m; i++){
          for(int j =1; j<=n; j++){
              if(pd[j-1] != '*'){
                if(s[i-1] == pd[j-1] || pd[j-1] == '?') _ismatch[i][j] = _ismatch[i-1][j-1];
                else _ismatch[i][j] = false;
              }else{
                    _ismatch[i][j] = _ismatch[i-1][j] || _ismatch[i][j-1];
              }
          }
      }
      return _ismatch[m][n];
    }
};