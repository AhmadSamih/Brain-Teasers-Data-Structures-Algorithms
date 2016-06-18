class Solution {
public:
    int calculate(string s) {
        
        /*stack based solution
        we push num on the stack, or we push -num based on the sign
        we keep pushing until we encounter a '*' or '/'. If so, we do op for the current num and top of stack and we push result.
        */
        
        stack<int> stk;
        char sign = '+';
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ') continue;
            if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-'){
                sign = s[i];
            }else if((i<s.size()-1 && !isdigit(s[i+1])) || i==s.size()-1){
                tmp+=s[i];
                int num = stoi(tmp);
                tmp = ""; //end of first num, start of new one
                if(sign == '+') stk.push(num);
                if(sign == '-') stk.push(-num);
                if(sign == '*'){
                    num = num * stk.top();
                    stk.pop(); stk.push(num);
                } 
                if(sign == '/'){
                    num = stk.top()/num;
                    stk.pop(); stk.push(num);
                } 
            }else{//continue capturing more chars of the num
                tmp+=s[i];
            }
        }
        
        int sum = 0;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        
      return sum;
    }
};