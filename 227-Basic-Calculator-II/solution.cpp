class Solution {
public:
    int calculate(string s) {
        
        stack<int>stk;
        
        vector<int>nums;
        vector<string>ops;
        
        //how about multi digit numbers ???????
        
        
        char * tmp = strdup(s.c_str());
        char * token = strtok(tmp, " +-/*");
        while(token){
            nums.push_back(stoi(token));
            token = strtok(NULL, " +-/*");
        }
        free(tmp);
        free(token);
        
        
        ops.push_back("+");
        tmp = strdup(s.c_str());
        token = strtok(tmp, " 0123456789");
        while(token){
            ops.push_back(token);
            token = strtok(NULL, " 0123456789");
        }
        free(tmp);
        free(token);
        
        for(int i=0; i<ops.size();i++){
            if(ops[i] == "+") {
                stk.push(nums[i]);
            }
            if(ops[i] == "-") {
                stk.push(-nums[i]);
            }
            if(ops[i] == "*") {
                int tmp = stk.top();
                stk.pop();
                stk.push(tmp*nums[i]);
            }
            if(ops[i] == "/") {
                int tmp = stk.top();
                stk.pop();
                stk.push(tmp/nums[i]);
            }
        }
        
        int sum = 0;
        while(!stk.empty()){
            sum+= stk.top();
            stk.pop();        
        }
        return sum;
    }
};