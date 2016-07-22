class Solution {
public:
  
    bool isNumber(string s) {
        bool isnum = false;
        if(s.empty())return isnum;
        if(s.size() == 1) return  isdigit(s[0]);

       int first = s.find_first_not_of(' ');
       int last = s.find_last_not_of(' ');
       s = s.substr(first, (last-first+1));

       bool e = false;
       bool dot = false;
        
        int i = 0;
        if(s[i] == '+'  || s[i] == '-')
            i++;
            
        for(;i<s.size(); i++){
            if(isdigit(s[i])){
                continue;
            }else if(!e && i>=1 && i<s.size()-1 && s[i]=='e'){
                e = true;
                if(i == 1) 
                    if(!(s[i-1]<= '9' && s[i-1] >= '0')) 
                        return false;
                if(s[i+1]=='+' || s[i+1]=='-'){
                    i++;
                    if(i+1 >= s.size()) return false;
                }
            }else if(!dot && !e && s[i] == '.'){
                dot = true;
                if( (i>=1 && (s[i-1]<= '9' && s[i-1] >= '0')) || (i<s.size()-1 && (s[i+1]<= '9' && s[i+1] >= '0'))){
                    continue;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
  
        return true;
        //check if first char is +- and ignore
        
        //check if we have an "e" 
            //if yes, look at both lhs/rhs
                //lhs, look for .
            
            //do same as lhs above
    }
};