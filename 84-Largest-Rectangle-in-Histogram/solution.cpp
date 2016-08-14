class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>stk; //to store the idx of each bar
        int m = 0;
        int i =0;
        while(i<heights.size()){
            if(stk.empty() || heights[stk.top()]<=heights[i])
                stk.push(i++);
            else{
                int top = stk.top();
                stk.pop();
                m = max(m, heights[top]*(stk.empty()?i : i-stk.top()-1));
                //note 1: why we need to stk.empty ? because we look up the stk
            }
        }
        
        while(!stk.empty()){
                    int top = stk.top();
                    stk.pop();
                    m = max(m, heights[top]*(stk.empty()?i : i-stk.top()-1));
        }
        return m;
    }
};