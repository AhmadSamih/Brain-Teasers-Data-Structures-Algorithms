class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int sum = 0;
        int num = 0;
        stack <int> stk;
        for(int i=0; i<s.size();i++){
            if(s[i] == '('){
                stk.push(sum); sum =0;
                stk.push(sign); sign =1;
            }else  if(s[i] == ')'){
                sum = sum * stk.top(); stk.pop();
                sum = sum + stk.top(); stk.pop();
            }else if(s[i] == '-'){
                sign = -1;
            }else if(isdigit(s[i])){
                num = num*10 + s[i]-'0';    
                if((i == s.size()-1) || (i < (s.size()-1) && !isdigit(s[i+1]))){
                    sum = sum + sign*num;
                    sign = 1;
                    num = 0;
                }
            }   
        }
        return sum;
    }
};