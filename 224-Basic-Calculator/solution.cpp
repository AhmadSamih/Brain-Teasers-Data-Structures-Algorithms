class Solution {
public:
    int calculate(string s) {
        
        if(s.size() == 0) return NULL;
        int mul = 1;
        int sum = 0;
        string last_num = "";
        stack <int> stk;
        
        for(int i=0; i<s.size();i++){
            
            if(s[i] == '('){
                stk.push(sum);
                stk.push(mul);
                sum = 0;
                mul = 1;
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
                mul = -1;
                continue;
            }
            
            last_num += s[i];
            
            if((i == s.size()-1) || (i < (s.size()-1) && isdigit(s[i+1])==false)){
                sum = sum + (mul * stoi(last_num));
                mul = 1;
                last_num = "";
            }
        }
        
        return sum;
        
    }
 
};