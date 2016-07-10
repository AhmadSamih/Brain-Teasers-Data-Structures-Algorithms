class Solution {
public:
    string shortestPalindrome(string s) {
        
        string tmp, tmp2, tmp3;
        
        tmp = s;
        reverse(tmp.begin(), tmp.end());
        
        if(tmp == s)
            return s;//nothing to add
            
        int idx = 1;
        int n =tmp.size();
        while(idx<n){
            
            tmp3 = s.substr(0, n -idx); 
            tmp2 = tmp.substr(idx);
            if(tmp2 == tmp3) return tmp.substr(0,idx)+s;
            idx++;
        }
        return tmp;
    }
};