class Solution {
public:
    int numDecodings(string s) {
     if(s.empty())return 0;
     if(s.size()==1 && s[0]=='0') return 0;
     vector<int>DP(s.size()+1,1);
     for(int i=2; i<=s.size();i++){
         int cur = s[i-1] - '0';
         int pre = s[i-2] - '0';
         if((pre==0 && i==2) || (cur==0 && (pre>2 || pre==0)))
            return 0;

         if( (pre==2 && cur<=6 && cur>0) || (pre==1 && cur<=9 && cur>0) )  {
             if(i<s.size() && s[i]=='0'){
                 DP[i] = DP[i-1];
             }else
                DP[i] = DP[i-1] + DP[i-2];
         }
        else{
            DP[i] = DP[i-1];
        }
     }

    return DP[s.size()];
    }
};


/*
[20-26]

[10-19]

[1-9]

[0] erros
*/