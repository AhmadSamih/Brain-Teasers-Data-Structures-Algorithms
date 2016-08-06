class Queue {
public:

    stack<int>stk1;
    stack<int>stk2;
    
    // Push element x to the back of queue.
    void push(int x) {
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        
        stk2.push(x);

        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk2.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (stk2.empty()==true);
    }
};