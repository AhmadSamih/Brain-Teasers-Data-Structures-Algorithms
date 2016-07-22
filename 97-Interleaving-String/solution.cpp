class Solution {
public:


int dyn(string s1, string s2, string s3){
    if(s1.size()+s2.size() != s3.size()) return 0;
    vector<vector<int>>DP(s1.size()+1, vector<int>(s2.size()+1, 0));
    
    DP[0][0] = 1;
    for(int i=1; i<=s1.size(); i++){
        if(s3[i-1]==s1[i-1])
            DP[i][0] = DP[i-1][0];
    }
    for(int j=1; j<=s2.size(); j++){
        if(s3[j-1]==s2[j-1])
            DP[0][j] = DP[0][j-1];
    }
    
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            if(s3[i+j-1] == s1[i-1] && s3[i+j-1] != s2[j-1]){
                DP[i][j] = DP[i-1][j];
            }
            else if(s3[i+j-1] != s1[i-1] && s3[i+j-1] == s2[j-1]){
                DP[i][j] = DP[i][j-1];
            }else if(s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1]){
                DP[i][j] = DP[i-1][j] || DP[i][j-1];
            }
            
        }
    }

    return DP[s1.size()][s2.size()];
}
/*
bool found;
string str;
void recur(string w1, int w1i, string w2, int w2i, string tmp){
  if(w1i== w1.size() && w2i==w2.size()){
      if(tmp == str) found = true;
    return;
  }
  if(found) return;
  if(w1i<w1.size()){
    recur(w1, w1i+1, w2, w2i, tmp+w1[w1i]);
  }
  if(w2i<w2.size()){
    recur(w1, w1i, w2, w2i+1, tmp+w2[w2i]);
  }
  
}
*/
bool isInterleave(string s1, string s2, string s3) {
    //str = s3;
    //recur(s1,0, s2,0, "");  
    return dyn(s1,s2,s3);
    
}
};