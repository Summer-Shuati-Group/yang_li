class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1; // the current stack representation
    queue<int> q2; // would always be empty after push() operation
    int size;
    MyStack() {
        size = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        size++;
        
        q2.push(x);
        
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q1.empty()) return -1;
        int temp = q1.front();
        q1.pop();
        size--;
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (size == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */