class Solution {
public:
    bool isValid(string s) {
        
        if(!s.size()) return true;
        if (s.size() &0x1) return false;

        bool result = false;

        char t00 = '(';
        char t01 = ')';

        char t10 = '{';
        char t11 = '}';

        char t20 = '[';
        char t21 = ']';

        stack<char> stack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t00 || s[i] == t10 || s[i] == t20) {//open
                stack.push(s[i]);
            }
            if(s[i] == t01 || s[i] == t11 || s[i] == t21) {//close
                if(stack.size()){
                    char p = stack.top();
                     if(p == t00 && s[i] == t01) result = true;
                    else if(p == t10 && s[i] == t11) result = true;
                    else if(p == t20 && s[i] == t21) result = true;
                    else return false;
                    stack.pop();
                }else return false;
            }

        }
        return result;
    }
};