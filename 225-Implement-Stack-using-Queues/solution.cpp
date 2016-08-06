class Stack {
public:
    deque<int>dq1;
    deque<int>dq2;
    // Push element x onto stack.
    void push(int x) {
        while(!dq2.empty()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        dq2.push_back(x);
        while(!dq1.empty()){
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        dq2.pop_front();
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