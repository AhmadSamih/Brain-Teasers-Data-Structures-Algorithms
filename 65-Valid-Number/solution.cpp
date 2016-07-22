class Solution {
public:
  
    bool isNumber(string s) {
        if(s.empty())return false;
        if(s.size() == 1) return  isdigit(s[0]);

       int first = s.find_first_not_of(' ');
       int last = s.find_last_not_of(' ');
       s = s.substr(first, (last-first+1));

       bool e = false; bool dot = false;
       for(int i=0;i<s.size(); i++){
            if(i==0 && (s[i]=='+' || s[i]=='-')){

            }else if(!e && i>=1 && i<s.size()-1 && s[i]=='e'){
                e = true;
                if(i == 1) 
                    if(!isdigit(s[i-1]))
                        return false;
                if(s[i+1]=='+' || s[i+1]=='-'){
                    i++;
                    if(i+1>= s.size()) 
                        return false;
                }
            }else if(!dot && !e && s[i] == '.'){
                dot = true;
                if(!((i>=1 && isdigit(s[i-1])) || (i<s.size()-1 && isdigit(s[i+1])))){ //to take care of 3. case
                    return false;
                }
            }else if(!isdigit(s[i]))
                return false;
        }
        return true;
        //check if first char is +- and ignore
        
        //check if we have an "e" 
            //if yes, look at both lhs/rhs
                //lhs, look for .
            
            //do same as lhs above
    }
};