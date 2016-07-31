class Solution {
public:
    
    int longestValidParentheses(string s) {
        stack<int>stk;
        int Max = 0;
        int LMax = 0;
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == '('){
                stk.push(i);
            }else{
                if(!stk.empty() && s[i]==')'&& s[stk.top()]=='(' )
                {
                    stk.pop();
                }
                else{
                    stk.push(i);
                }
            }
        }

        int right = s.size();        
        while(!stk.empty()){
            LMax = right - stk.top() -1;
            Max = max(Max, LMax);
            right = stk.top();
            stk.pop();
        }
        
        return max(Max, right);

    }
};