class Solution {
public:
    int calculate(string s) {
        
        if(s.size() == 0) return NULL;
        int sign = 1;
        int sum = 0;
        string last_num = "";
        stack <int> stk;
        
        for(int i=0; i<s.size();i++){
            
            if(s[i] == '('){
                stk.push(sum);
                stk.push(sign);
                sum = 0;
                sign = 1;
                continue;
            }
            if(s[i] == ')'){
                sum = sum * stk.top();
                stk.pop();
                sum = sum + stk.top();
                stk.pop();
                continue;
            }
            
            if(s[i]==' ' || s[i] == '+')
                continue;
                
            if(s[i] == '-'){
                sign = -1;
                continue;
            }
            
            last_num += s[i];
            
            if((i == s.size()-1) || (i < (s.size()-1) && !isdigit(s[i+1]))){
                sum = sum + (sign * stoi(last_num));
                sign = 1;
                last_num = "";
            }
        }
        
        return sum;
        
    }
 
};