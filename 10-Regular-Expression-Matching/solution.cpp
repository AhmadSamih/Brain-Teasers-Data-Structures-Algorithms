class Solution {
public:
    bool isMatch(string s, string p) {
      int m = s.size(), n = p.size(); 
      vector<vector<bool>> _ismatch(m + 1, vector<bool>(n + 1));
      _ismatch[0][0] = true;

       for(int j = 1; j <=n; j++){
           if(p[j-1] == '*')
            _ismatch[0][j] = (j>1 &&_ismatch[0][j-2]);
       }

       for(int i =1; i<=m; i++){
          for(int j =1; j<=n; j++){
            if(p[j-1] == '*')
                _ismatch[i][j] = (j>1 &&_ismatch[i][j-2]) || (_ismatch[i-1][j]&&(p[j-2]==s[i-1] || p[j-2]=='.'));
            else{
                _ismatch[i][j] = (s[i-1] == p[j-1] || p[j-1] == '.') && _ismatch[i-1][j-1];
            }
          }
      }
      return _ismatch[m][n];

    }
};