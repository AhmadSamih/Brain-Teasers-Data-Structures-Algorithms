class MinStack {
public:
    /** initialize your data structure here. */
    deque<int>dq;
    deque<int> Min;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(Min.empty()) 
            Min.push_front(x);
        else
            Min.push_front(min(Min.front(), x));
            
        dq.push_front(x);
    }
    
    void pop() {
        dq.pop_front();
        Min.pop_front();
    }
    
    int top() {
        return dq.front();
    }
    
    int getMin() {
        return Min.front();
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