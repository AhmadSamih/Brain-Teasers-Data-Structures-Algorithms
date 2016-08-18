class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        stack<int>stk;
        string tmp = "";
        char sign = '+';
        
        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                tmp.push_back(s[i]);                            
                if(i<s.size()-1 && !isdigit(s[i+1])){
                    int num = stoi(tmp);
                    if(sign == '+')
                        stk.push(num);
                    if(sign == '-')
                        stk.push(-num);
                    if(sign == '*'){
                        int eval = stk.top()*num;
                        stk.pop(); stk.push(eval);
                    }
                    if(sign =='/'){
                        int eval = stk.top()/num;
                        stk.pop(); stk.push(eval);
                    }
                    tmp.clear();
                }
            }else if(s[i]!=' '){
                sign = s[i];
            }
        }
        
        int sum = 0;
        while(!stk.empty()){
            sum+=stk.top();
            stk.pop();
        }
        
        return sum;
    }
};