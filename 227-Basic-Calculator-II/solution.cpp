class Solution {
public:
    int calculate(string s) {
        vector<char>ops = {'+'};//inial sign of first number
        vector<int>nums;
        stack<int>stk;
        
        /*tokensize and extract numbers into a vector*/
        char * dup = strdup(s.c_str());
        char *token = strtok(dup, "+-/* ");
        while(token){
            nums.push_back(atoi(token));
            token = strtok(NULL, "+-/* ");
        }
        free(dup);
        free(token);
        
        /*extract ops into another vector*/
        for(int i=0; i<s.size();i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                ops.push_back(s[i]);
            }
        }

        /*do math operations*/
        for(int i=0; i<ops.size();i++){
            if(ops[i] == '+') stk.push(nums[i]);
            if(ops[i] == '-') stk.push(-nums[i]);
            if(ops[i] == '*') { int res = nums[i]*stk.top(); stk.pop(); stk.push(res);}
            if(ops[i] == '/') { int res = stk.top()/nums[i]; stk.pop(); stk.push(res);}
        }

        /*sum up all stack entries*/
        int sum = 0;
        while(!stk.empty()){
            sum +=stk.top();
            stk.pop();
        }
        
        return sum;
    }
};