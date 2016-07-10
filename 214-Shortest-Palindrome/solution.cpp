class Solution {
public:
    string shortestPalindrome(string s) {
        
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        
        if(tmp == s) {return s; }//nothing to add
        int idx = 1;
        int n =tmp.size();
        while(idx<tmp.size()){
            
            string tmp2 = tmp.substr(idx);
            string tmp3 = s.substr(0, n -idx); 
            if(tmp2 == tmp3) {cout<<tmp2.substr(0,idx) << " "<< s<<endl; return tmp.substr(0,idx)+s;}
            idx++;
        }
        return tmp;
    }
};