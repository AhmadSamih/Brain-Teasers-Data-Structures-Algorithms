class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        stack<int>stk;
        int left=0;
        char sign = '+';
        
        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                if(i<s.size()-1 && !isdigit(s[i+1])){
                    int num = stoi(s.substr(left, i-left+1));
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
                }
            }else if(s[i]!=' '){
                sign = s[i];
            }
            if(!isdigit(s[i]))
                left = i+1;
        }
        
        int sum = 0;
        while(!stk.empty()){
            sum+=stk.top();
            stk.pop();
        }
        
        return sum;
    }
};