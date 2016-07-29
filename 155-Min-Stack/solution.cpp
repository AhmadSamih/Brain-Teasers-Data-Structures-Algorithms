class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>dq;
    stack<int> Min;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(Min.empty()) 
            Min.push(x);
        else
            Min.push(min(Min.top(), x));
            
        dq.push(x);
    }
    
    void pop() {
        dq.pop();
        Min.pop();
    }
    
    int top() {
        return dq.top();
    }
    
    int getMin() {
        return Min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */