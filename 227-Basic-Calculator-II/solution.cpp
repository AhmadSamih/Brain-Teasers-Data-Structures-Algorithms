class Solution {
public:
    int calculate(string s) {
        
        vector<int>num;
        char * dup = strdup(s.c_str());
        char * token = strtok(dup, " +-/*");
        while(token){
            num.push_back(stoi(token));
            token = strtok(NULL, " +-/*");
        }
        free(dup);
        free(token);

        vector<char>ops;
        ops.push_back('+');
        for(int i=0; i<s.size();i++)
            if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
                ops.push_back(s[i]);
            
        stack<int>stk;    
        for(int i=0; i<ops.size();i++){
            if(ops[i] == '+')
                stk.push(num[i]);
            if(ops[i] == '-')
                stk.push(-num[i]);
            if(ops[i] == '*'){
                int res = stk.top() * num[i];
                stk.pop();
                stk.push(res);
            }
            if(ops[i] == '/'){
                int res = stk.top() / num[i];
                stk.pop();
                stk.push(res);
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