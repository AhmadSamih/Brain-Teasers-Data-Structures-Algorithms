class Stack {
public:
    queue<int>dq1;
    queue<int>dq2;
    // Push element x onto stack.
    void push(int x) {
        while(!dq2.empty()){
            dq1.push(dq2.front());
            dq2.pop();
        }
        dq2.push(x);
        while(!dq1.empty()){
            dq2.push(dq1.front());
            dq1.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        dq2.pop();
    }

    // Get the top element.
    int top() {
        return dq2.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return (dq2.empty() == true);
    }
};